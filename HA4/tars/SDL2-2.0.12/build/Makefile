# Makefile to build and install the SDL library

top_builddir = .
srcdir  = /home/juice100/Documents/Dokumente/Uni/5. Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12
objects = build
gen = gen
prefix = /home/juice100/SDL
exec_prefix = ${prefix}
bindir	= ${exec_prefix}/bin
libdir  = ${exec_prefix}/lib
includedir = ${prefix}/include
datarootdir = ${prefix}/share
datadir	= ${datarootdir}
auxdir	= ../build-scripts
distpath = $(srcdir)/..
distdir = SDL2-2.0.12
distfile = $(distdir).tar.gz


SHELL	= /bin/bash
CC      = gcc
INCLUDE = -I/home/juice100/Documents/Dokumente/Uni/5. Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/include -idirafter /home/juice100/Documents/Dokumente/Uni/5. Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/video/khronos
CFLAGS  = -g -O3 -DUSING_GENERATED_CONFIG_H
EXTRA_CFLAGS = -I/home/juice100/Documents/Dokumente/Uni/5. Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/include -idirafter /home/juice100/Documents/Dokumente/Uni/5. Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/video/khronos  -D_REENTRANT 
LDFLAGS = 
EXTRA_LDFLAGS =  -lpulse-simple -lpulse -ljack
LIBTOOL = $(SHELL) $(top_builddir)/libtool
INSTALL = /usr/bin/install -c
AR	= ar
RANLIB	= ranlib
WINDRES	= :

TARGET  = libSDL2.la
OBJECTS = /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/SDL_ime.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/SDL_threadprio.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo
GEN_HEADERS = 
GEN_OBJECTS = 
VERSION_OBJECTS = 

SDLMAIN_TARGET = libSDL2main.la
SDLMAIN_OBJECTS = /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo

SDLTEST_TARGET = libSDL2_test.la
SDLTEST_OBJECTS = /home/juice100/Documents/Dokumente/Uni/5. $(objects)/*.lo

WAYLAND_SCANNER = 

INSTALL_SDL2_CONFIG = TRUE

SRC_DIST = *.txt acinclude Android.mk autogen.sh android-project build-scripts cmake cmake_uninstall.cmake.in configure configure.ac debian docs include Makefile.* sdl2-config.cmake.in sdl2-config-version.cmake.in sdl2-config.in sdl2.m4 sdl2.pc.in SDL2.spec.in SDL2Config.cmake src test VisualC.html VisualC VisualC-WinRT Xcode Xcode-iOS wayland-protocols
GEN_DIST = SDL2.spec

ifneq ($V,1)
RUN_CMD_AR     = @echo "  AR    " $@;
RUN_CMD_CC     = @echo "  CC    " $@;
RUN_CMD_CXX    = @echo "  CXX   " $@;
RUN_CMD_LTLINK = @echo "  LTLINK" $@;
RUN_CMD_RANLIB = @echo "  RANLIB" $@;
RUN_CMD_GEN    = @echo "  GEN   " $@;
LIBTOOL += --quiet
endif

HDRS = \
	SDL.h \
	SDL_assert.h \
	SDL_atomic.h \
	SDL_audio.h \
	SDL_bits.h \
	SDL_blendmode.h \
	SDL_clipboard.h \
	SDL_cpuinfo.h \
	SDL_egl.h \
	SDL_endian.h \
	SDL_error.h \
	SDL_events.h \
	SDL_filesystem.h \
	SDL_gamecontroller.h \
	SDL_gesture.h \
	SDL_haptic.h \
	SDL_hints.h \
	SDL_joystick.h \
	SDL_keyboard.h \
	SDL_keycode.h \
	SDL_loadso.h \
	SDL_log.h \
	SDL_main.h \
	SDL_messagebox.h \
	SDL_metal.h \
	SDL_mouse.h \
	SDL_mutex.h \
	SDL_name.h \
	SDL_opengl.h \
	SDL_opengl_glext.h \
	SDL_opengles.h \
	SDL_opengles2_gl2ext.h \
	SDL_opengles2_gl2.h \
	SDL_opengles2_gl2platform.h \
	SDL_opengles2.h \
	SDL_opengles2_khrplatform.h \
	SDL_pixels.h \
	SDL_platform.h \
	SDL_power.h \
	SDL_quit.h \
	SDL_rect.h \
	SDL_render.h \
	SDL_rwops.h \
	SDL_scancode.h \
	SDL_sensor.h \
	SDL_shape.h \
	SDL_stdinc.h \
	SDL_surface.h \
	SDL_system.h \
	SDL_syswm.h \
	SDL_thread.h \
	SDL_timer.h \
	SDL_touch.h \
	SDL_types.h \
	SDL_version.h \
	SDL_video.h \
	SDL_vulkan.h \
	begin_code.h \
	close_code.h

SDLTEST_HDRS = $(shell ls $(srcdir)/include | fgrep SDL_test)

LT_AGE      = 12
LT_CURRENT  = 12
LT_RELEASE  = 2.0
LT_REVISION = 0
LT_LDFLAGS  = -no-undefined -rpath $(libdir) -release $(LT_RELEASE) -version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE)

all: $(srcdir)/configure Makefile $(objects)/$(TARGET) $(objects)/$(SDLMAIN_TARGET) $(objects)/$(SDLTEST_TARGET)

$(srcdir)/configure: $(srcdir)/configure.ac
	@echo "Warning, configure is out of date, please re-run autogen.sh"

Makefile: $(srcdir)/Makefile.in
	$(SHELL) config.status $@

Makefile.in:;

$(objects)/.created:
	$(SHELL) $(auxdir)/mkinstalldirs $(objects)
	touch $@

update-revision:
	$(SHELL) $(auxdir)/updaterev.sh

.PHONY: all update-revision install install-bin install-hdrs install-lib install-data uninstall uninstall-bin uninstall-hdrs uninstall-lib uninstall-data clean distclean dist $(OBJECTS:.lo=.d)

$(objects)/$(TARGET): $(GEN_HEADERS) $(GEN_OBJECTS) $(OBJECTS) $(VERSION_OBJECTS)
	$(RUN_CMD_LTLINK)$(LIBTOOL) --tag=CC --mode=link $(CC) -o $@ $(OBJECTS) $(GEN_OBJECTS) $(VERSION_OBJECTS) $(LDFLAGS) $(EXTRA_LDFLAGS) $(LT_LDFLAGS)

$(objects)/$(SDLMAIN_TARGET): $(SDLMAIN_OBJECTS)
	$(RUN_CMD_LTLINK)$(LIBTOOL) --tag=CC --mode=link $(CC) -static -o $@ $(SDLMAIN_OBJECTS) -rpath $(libdir)

$(objects)/$(SDLTEST_TARGET): $(SDLTEST_OBJECTS)
	$(RUN_CMD_LTLINK)$(LIBTOOL) --tag=CC --mode=link $(CC) -static -o $@ $(SDLTEST_OBJECTS) -rpath $(libdir)

install: all install-bin install-hdrs install-lib install-data
install-bin:
ifeq ($(INSTALL_SDL2_CONFIG),TRUE)
	$(SHELL) $(auxdir)/mkinstalldirs $(DESTDIR)$(bindir)
	$(INSTALL) -m 755 sdl2-config $(DESTDIR)$(bindir)/sdl2-config
endif

install-hdrs: update-revision
	$(SHELL) $(auxdir)/mkinstalldirs $(DESTDIR)$(includedir)/SDL2
	for file in $(HDRS) $(SDLTEST_HDRS); do \
	    $(INSTALL) -m 644 $(srcdir)/include/$$file $(DESTDIR)$(includedir)/SDL2/$$file; \
	done
	$(INSTALL) -m 644 include/SDL_config.h $(DESTDIR)$(includedir)/SDL2/SDL_config.h
	if test -f include/SDL_revision.h; then \
	    $(INSTALL) -m 644 include/SDL_revision.h $(DESTDIR)$(includedir)/SDL2/SDL_revision.h; \
	else \
	    $(INSTALL) -m 644 $(srcdir)/include/SDL_revision.h $(DESTDIR)$(includedir)/SDL2/SDL_revision.h; \
	fi

install-lib: $(objects) $(objects)/$(TARGET) $(objects)/$(SDLMAIN_TARGET) $(objects)/$(SDLTEST_TARGET)
	$(SHELL) $(auxdir)/mkinstalldirs $(DESTDIR)$(libdir)
	$(LIBTOOL) --mode=install $(INSTALL) $(objects)/$(TARGET) $(DESTDIR)$(libdir)/$(TARGET)
	$(LIBTOOL) --mode=install $(INSTALL) $(objects)/$(SDLMAIN_TARGET) $(DESTDIR)$(libdir)/$(SDLMAIN_TARGET)
	$(LIBTOOL) --mode=install $(INSTALL) $(objects)/$(SDLTEST_TARGET) $(DESTDIR)$(libdir)/$(SDLTEST_TARGET)
install-data:
	$(SHELL) $(auxdir)/mkinstalldirs $(DESTDIR)$(datadir)/aclocal
	$(INSTALL) -m 644 $(srcdir)/sdl2.m4 $(DESTDIR)$(datadir)/aclocal/sdl2.m4
	$(SHELL) $(auxdir)/mkinstalldirs $(DESTDIR)$(libdir)/pkgconfig
	$(INSTALL) -m 644 sdl2.pc $(DESTDIR)$(libdir)/pkgconfig
ifeq ($(INSTALL_SDL2_CONFIG),TRUE)
	$(SHELL) $(auxdir)/mkinstalldirs $(DESTDIR)$(libdir)/cmake/SDL2
	$(INSTALL) -m 644 sdl2-config.cmake $(DESTDIR)$(libdir)/cmake/SDL2
	$(INSTALL) -m 644 sdl2-config-version.cmake $(DESTDIR)$(libdir)/cmake/SDL2
endif

uninstall: uninstall-bin uninstall-hdrs uninstall-lib uninstall-data
uninstall-bin:
	rm -f $(DESTDIR)$(bindir)/sdl2-config
uninstall-hdrs:
	for file in $(HDRS) $(SDLTEST_HDRS); do \
	    rm -f $(DESTDIR)$(includedir)/SDL2/$$file; \
	done
	rm -f $(DESTDIR)$(includedir)/SDL2/SDL_config.h
	rm -f $(DESTDIR)$(includedir)/SDL2/SDL_revision.h
	-rmdir $(DESTDIR)$(includedir)/SDL2
uninstall-lib:
	$(LIBTOOL) --mode=uninstall rm -f $(DESTDIR)$(libdir)/$(TARGET)
	rm -f $(DESTDIR)$(libdir)/$(SDLMAIN_TARGET)
	rm -f $(DESTDIR)$(libdir)/$(SDLTEST_TARGET)
uninstall-data:
	rm -f $(DESTDIR)$(datadir)/aclocal/sdl2.m4
	rm -f $(DESTDIR)$(libdir)/pkgconfig/sdl2.pc
	rm -f $(DESTDIR)$(libdir)/cmake/SDL2/sdl2-config.cmake
	rm -f $(DESTDIR)$(libdir)/cmake/SDL2/sdl2-config-version.cmake

clean:
	rm -rf $(objects)
	rm -rf $(gen)
	if test -f test/Makefile; then (cd test; $(MAKE) $@); fi

distclean: clean
	rm -f Makefile Makefile.rules sdl2-config
	rm -f config.status config.cache config.log libtool
	rm -rf $(srcdir)/autom4te*
	find $(srcdir) \( \
	    -name '*~' -o \
	    -name '*.bak' -o \
	    -name '*.old' -o \
	    -name '*.rej' -o \
	    -name '*.orig' -o \
	    -name '.#*' \) \
	    -exec rm -f {} \;
	if test -f test/Makefile; then (cd test; $(MAKE) $@); fi

dist $(distfile):
	$(SHELL) $(auxdir)/mkinstalldirs $(distdir)
	(cd $(srcdir); tar cf - $(SRC_DIST)) | (cd $(distdir); tar xf -)
	tar cf - $(GEN_DIST) | (cd $(distdir); tar xf -)
	find $(distdir) \( \
	    -name '*~' -o \
	    -name '*.bak' -o \
	    -name '*.old' -o \
	    -name '*.rej' -o \
	    -name '*.orig' -o \
	    -name '.#*' \) \
	    -exec rm -f {} \;
	if test -f $(distdir)/test/Makefile; then (cd $(distdir)/test && make distclean); fi
	(cd $(distdir); build-scripts/updaterev.sh)
	tar cvf - $(distdir) | gzip --best >$(distfile)
	rm -rf $(distdir)

rpm: $(distfile)
	rpmbuild -ta $?

# Build rules for objects
-include $(OBJECTS:.lo=.d)

# Special dependency for SDL.c, since it depends on SDL_revision.h
/home/juice100/Documents/Dokumente/Uni/5. Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/SDL.c: update-revision
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/atomic/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/audio/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/cpuinfo/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/dynapi/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/events/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/file/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/haptic/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/joystick/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/libm/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/power/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/render/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/render/*/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/sensor/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/stdlib/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/thread/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/timer/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/video/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/video/yuv2rgb/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/video/dummy/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/audio/disk/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/audio/dummy/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/audio/pulseaudio/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/audio/jack/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/SDL_ime.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/core/linux/SDL_ime.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/joystick/linux/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/joystick/steam/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/power/linux/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/filesystem/unix/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/timer/unix/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/SDL_threadprio.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/core/linux/SDL_threadprio.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/core/unix/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/haptic/dummy/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/sensor/dummy/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/thread/generic/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5.

$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/loadso/dummy/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@

/home/juice100/Documents/Dokumente/Uni/5. 
$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/main/dummy/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
/home/juice100/Documents/Dokumente/Uni/5. 
$(objects)/*.lo: Semester/SysProg/Homework/HA4/tars/SDL2-2.0.12/src/test/*.c $(objects)/.created
	$(RUN_CMD_CC)$(LIBTOOL) --tag=CC --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@

