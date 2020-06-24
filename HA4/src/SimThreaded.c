/**
 * @file SimThreaded.c
 * @brief Multi-threaded simulation of different distancing scenarios.
 * @version 1.1
 * @date 2020-06-21
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h> // for memset

#include "Params.h"
#include "Scenario.h"
#ifdef GUI_MODE
	#include "GUI.h"
#else
	#include "CSV.h"
#endif // GUI_MODE

typedef struct Sim Sim;

struct Sim
{
	unsigned int seed;           // simulation seed for rand
	Args args[SCENARIO_NUM];     // arguments for each scenario
	int iteration_num;           // total iterations
	Scenario *s[SCENARIO_NUM];   // data for simulation Scenario

	#ifdef GUI_MODE
	    GUI *gui;                // data for GUI mode
	#else
	    CSV *csv;                // data for headless mode
	#endif // GUI_MODE

	int active_iteration;        // current iteration

	bool running;                // false when iteration should end

	State states[SCENARIO_NUM];  // each scenario's state variable

	// TODO BEGIN
	// A) Create variable to store thread reference
	pthread_t scn_thread[SCENARIO_NUM];

	// C) Create mutex and signal variables for synchronisation
	pthread_cond_t new_sim_cond[SCENARIO_NUM];
	pthread_cond_t done_cond[SCENARIO_NUM];
	pthread_mutex_t new_sim_mutex[SCENARIO_NUM];

	// TODO END
};

/////////////////////////////////
// declaration local functions //
/////////////////////////////////

/** 
 * Initialize the argument struct array with the values for each
 * scenario. Should be called by Sim_CLIParseSim().
 * @param args array of size SCENARIO_NUM
 * @param iteration_num number of total iterations
 * @param argc from main(argc, argv)
 * @param argv from main(argc, argv)
 */
static void Sim_ArgsInit(Args *args, int iteration_num, int argc, char **argv);

/**
 * Calculate new simulation state. Moves the people and checks for new
 * infections. Should be called by main().
 * NEW: Invokes the scenario threads and then waits for them to finish.
 * @param sim initialized simulation
 */
static void Sim_CalcActiveIteration(Sim *sim);

/**
 * Gives the allocated memory inside sim free. Does not free sim. Should be
 * called by main().
 * NEW: Cleans up the threads.
 * @param sim simulation to be cleaned
 */
static void Sim_Cleanup(Sim *sim);

/**
 * Check for help flag in CLI and output help when flag set.
 * @param argc main(argc, argv)
 * @param argv main(argc, argv)
 * @return 1 when help flag is set, else 0
 */
static int Sim_CLIHasHelpFlag(int argc, char** argv);

/**
 * Parse CLI for scenario parameters. Should be called by Sim_ArgsInit().
 * @param sim initialized simulation
 * @param argc from main(argc, argv)
 * @param argv from main(argc, argv)
 */
static void Sim_CLIParseScenarioArgs(Args *args, int argc, char **argv);

/**
 * Parse CLI for simluation parameters. Should be called by Sim_Init().
 * @param sim initialized simulation
 * @param argc from main(argc, argv)
 * @param argv from main(argc, argv)
 */
static void Sim_CLIParseSim(Sim *sim, int argc, char **argv);

/**
 * Set the simulation to end in the next iteration.
 * Continue or break should be executed after this function.
 * Should be called by main().
 * NEW: Also inform the scenario threads to end.
 * @param sim initialized simulation
 */
static void Sim_End(Sim *sim);

/**
 * Peek the user input. Currently only checks for exit in GUI mode.
 * @param sim initialized simulation
 * @return user command
 */
static UserInput Sim_GetUserInput(Sim *sim);

/**
 * Initialize Simulation. Should be called by main().
 * NEW: Initialize mutexes, variables and signals.
 * @param sim allocated, not-initialized simulation
 * @param argc from main(argc, argv)
 * @param argv from main(argc, argv)
 */
static void Sim_Init(Sim *sim, int argc, char **argv);

/**
 * Output current state to user. GUI and CSV mode depending on the value of
 * GUI_MODE.
 * Should be called by main().
 * @param sim Initialized simulation
 */
static void Sim_Output(const Sim *sim);

/////////////////////////////////
// definition global functions //
/////////////////////////////////

/**
 * Runs multiple simulation scenarios with different social distancing percentages.
 * Call: ./SimThreaded [SEED] [ITERATIONS] [SCEN1_DIST_%] [SCEN2_DIST_%] ...
 * @param argc number of command line arguments + 1
 * @param argv array of size argc.
 */
int main(int argc, char *argv[])
{
	Sim sim;

	if (Sim_CLIHasHelpFlag(argc, argv))
	{
		return EXIT_SUCCESS;
	}

	Sim_Init(&sim, argc, argv);

	// run simulations
	while (sim.running)
	{
		if (sim.active_iteration >= sim.iteration_num)
		{
			Sim_End(&sim);
			continue;
		}

		switch (Sim_GetUserInput(&sim))
		{
			case COMMAND_QUIT:
				Sim_End(&sim);
				continue;
			case COMMAND_EMPTY:
				break;
		}

		Sim_Output(&sim);

		sim.active_iteration++;

		Sim_CalcActiveIteration(&sim);
	}

	Sim_Cleanup(&sim);

	return EXIT_SUCCESS;
}

////////////////////////////////
// definition local functions //
////////////////////////////////

static void Sim_ArgsInit(Args *args, int iteration_num, int argc, char **argv)
{
	int i;
	// set defaults
	args[0].distancing_perc = 95.0;
	for (i = 1; i < SCENARIO_NUM; ++i)
	{
		args[i].distancing_perc = args[i - 1].distancing_perc * 0.95;
	}

	for (i = 0; i < SCENARIO_NUM; ++i)
	{
		args[i].iteration_num = iteration_num;
	}

	// override defaults with user input
	Sim_CLIParseScenarioArgs(args, argc, argv);
}

static void Sim_CalcActiveIteration(Sim *sim)
{
	// TODO BEGIN
	// D) Implement this function: Invoke the scenario threads
	//    Wait for scenario threads to finish one iteration.
	for (int i=0; i<SCENARIO_NUM; i++){
		pthread_mutex_lock(sim->args[i].new_sim_mutex);

		sim->states[i] = NEXT_STATE;
		pthread_cond_signal(&sim->new_sim_cond[i]);
		pthread_mutex_unlock(sim->args[i].new_sim_mutex);

	}

	// new_state = new_sim_cond
	// iteration_fin = done_cond

	for (int i=0; i<SCENARIO_NUM; i++){
		pthread_mutex_lock(sim->args[i].new_sim_mutex);

		while(sim->states[i] != WAITING){
			pthread_cond_wait(sim->args[i].done_cond, sim->args[i].new_sim_mutex);
		}
		
		pthread_mutex_unlock(sim->args[i].new_sim_mutex);
		
	}
	
	// TODO END
}

static void Sim_Cleanup(Sim *sim)
{
	// TODO BEGIN

	// A) Wait for threads to end
	for (int i = 0; i < SCENARIO_NUM; i++){
        pthread_join(sim->scn_thread[i], NULL);
	}

	// C) Handle mutexes and signals!
	for (int i = 0; i < SCENARIO_NUM; i++){
        pthread_mutex_destroy(&sim->new_sim_mutex[i]);
		pthread_cond_destroy(&sim->new_sim_cond[i]);
	}

	for (int i = 0; i < SCENARIO_NUM; i++){
        Scenario_DataDestroy(sim->s[i]);
	}
	

	// TODO END
	
	#ifdef GUI_MODE
		GUI_Destroy(sim->gui);
	#else
		CSV_Destroy(sim->csv);
	#endif // GUI_MODE
}

static int Sim_CLIHasHelpFlag(int argc, char** argv)
{
	int i;

	if (argc > 1 && ( 0 == strncmp("--help", argv[1], 8)
	              || 0 == strncmp ("-h", argv[1], 3) ) )
	{
		printf("Usage: %s [SEED] [NUMBER OF ITERATIONS]", argv[0]);
		for (i = 0; i < SCENARIO_NUM; ++i)
		{
			printf(" [SCENARIO %d DISTANCING PERCENTAGE]", i + 1);
		}
		printf("\n");
		return true;
	}

	return false;
}

static void Sim_CLIParseScenarioArgs(Args *args, int argc, char **argv)
{
	int i;
	const int arg_offset = 3;
	for (i = arg_offset; i < argc; i++)
	{
		// keep distancing perc in range [0,100]
		args[i - arg_offset].distancing_perc = MAX(0.0, MIN(100.0, strtof(argv[i], NULL) ));
	}
}

static void Sim_CLIParseSim(Sim *sim, int argc, char **argv)
{
	if (argc >= 3) sim->iteration_num = strtol(argv[2], NULL, 10);
	if (argc >= 2) sim->seed = strtol(argv[1], NULL, 10);

	Sim_ArgsInit(sim->args, sim->iteration_num, argc, argv);
}

static void Sim_End(Sim *sim)
{
	sim->running = false;
	// TODO BEGIN
	// D) Implement this function: Invoke the scenario threads
	//    Wait for scenario threads to finish one iteration.

	for (int i = 0; i < SCENARIO_NUM; i++){
		pthread_mutex_lock(&sim->new_sim_mutex[i]);
        sim->states[i] = FINISHED;
		pthread_cond_signal(&sim->new_sim_cond[i]);
		pthread_mutex_unlock(&sim->new_sim_mutex[i]);
	}
	// TODO END
}

static UserInput Sim_GetUserInput(__attribute__((unused)) Sim *sim)
{
	#ifdef GUI_MODE
		return (GUI_HandleUserInput(sim->gui));
	#else
		return COMMAND_EMPTY;
	#endif // GUI_MODE

}

static void Sim_Init(Sim *sim, int argc, char **argv)
{
	int i;

	memset(sim, 0, sizeof (Sim));
	// Initialize Simulation
	sim->iteration_num = SIM_DEFAULT_ITERATION_NUM;
	sim->running = true;
	Sim_CLIParseSim(sim, argc, argv);


	// initialize simulation output	
	#ifdef GUI_MODE // output as GUI
		sim->gui = GUI_Create();
	#else  // output as CSV
		float distancing_pers[SCENARIO_NUM];
		for (i = 0; i < SCENARIO_NUM; ++i)
		{
			distancing_pers[i] = sim->args[i].distancing_perc;
		}
		sim->csv = CSV_Create("SimThreaded.csv", sim->seed, distancing_pers);
	#endif // GUI_MODE

	for (i = 0; i < SCENARIO_NUM; i++)
	{
		// TODO BEGIN
		sim->states[i] = WAITING;
		sim->args[i].state = &sim->states[i];
		// C) Handle mutexe and signals
		pthread_mutex_init(&sim->new_sim_mutex[i], NULL);
		pthread_cond_init(&sim->new_sim_cond[i], NULL);
		pthread_cond_init(&sim->done_cond[i], NULL);
		sim->args[i].new_sim_mutex = &sim->new_sim_mutex[i];
		sim->args[i].new_sim_cond = &sim->new_sim_cond[i];
		sim->args[i].done_cond = &sim->done_cond[i];

		// A) Start threads, save reference in sim

		sim->s[i] = Scenario_Create(&sim->args[i]);
		pthread_create(&sim->scn_thread[i], NULL, Scenario_Main, sim->s[i]);
		
	}
}

static void Sim_Output(const Sim *sim)
{
	int i;
	#ifdef GUI_MODE
		Person *persons[SCENARIO_NUM];

		for (i = 0; i < SCENARIO_NUM; ++i)
		{
			persons[i] = Scenario_GetPersons(sim->s[i]);
		}
		GUI_WaitNextFrame(sim->gui);
		GUI_Update(sim->gui, persons, SCENARIO_NUM);
	#else
		float infected[SCENARIO_NUM];
		for (i = 0; i < SCENARIO_NUM; ++i)
		{
			infected[i] = (float) Scenario_GetInfected(sim->s[i], sim->active_iteration) / PERSON_NUM;
		}
		CSV_Output(sim->csv, sim->active_iteration, infected);

		// print percentage in stdout
		if (sim->iteration_num < 100 || sim->active_iteration % (sim->iteration_num / 100) == 0)
			printf("%.2f%%\n", 100.0 * sim->active_iteration / sim->args[0].iteration_num);
	#endif // GUI_MODE
}
