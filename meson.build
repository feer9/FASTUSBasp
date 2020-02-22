project('fastusbaspv2', 'cpp')

compiler_obj = meson.get_compiler('cpp')

size = find_program('arm-none-eabi-size')
objcopy = find_program('arm-none-eabi-objcopy')
stinfo = find_program('st-info')
stflash = find_program('st-flash')
stm32flash = find_program('stm32flash')


#define libopencm3 path here
libocm3Path = '/home/feer/stm32/libopencm3'

#define cpu types here
cputype = 'cortex-m4'
cpudefine = 'STM32F4'
libocm3cputype = 'opencm3_stm32f4'

#Add your source files here
srcfiles = ['src/main.cpp']


libocm3IncPath = libocm3Path + '/include'
libocm3LibPath = libocm3Path + '/lib'
libocm3LibPath2 = libocm3Path + '/lib/stm32/f4'

# check for libopencm3 library
libocm3lib_dep = compiler_obj.find_library(libocm3cputype, required: true, dirs: libocm3LibPath)
if libocm3lib_dep.found() == true
   message('Found libopencm3 library at ' + libocm3Path)
else
   error('unable to find libopencm3 library')
endif

libocm3_incdir = include_directories(libocm3IncPath)


myfoolib_path= '../lib'
stm32f4cargs = ['-Os',
                '-ggdb',
                #'-g',
                '-mcpu=' + cputype,
                '-mthumb',
                '-mfpu=fpv4-sp-d16',
                '-mfloat-abi=hard',
                '-std=gnu++14',
                '-Wall',
                '-ffunction-sections',
                '-fdata-sections',
                '-D' + cpudefine,
#                '-DDEBUG',
                '-fdata-sections',
                '-fno-exceptions',
                '-I' + myfoolib_path,
#'-I' + libocm3IncPath
#'-mhard-float',

                '-fno-use-cxa-atexit',
                ]

stm32f4linkargs = ['-Os',
                   '-ggdb',
                   #'-g',
                   '-D' + cpudefine,
                   '-fdata-sections',
                   '-mcpu=' + cputype,
                   '-mfpu=fpv4-sp-d16',
                   '-mthumb',
                   '-mfloat-abi=hard',
#                   '-mhard-float',
                   '-lc',
                   '-flto',
#'-T../libopencm3_f4.ld',
                   '-T' + meson.current_source_dir() + '/libopencm3.ld',
                   '--specs=nosys.specs',
                   '-nostartfiles',
                   '-Wl,--gc-sections',
                   '-L' + libocm3LibPath,
                   '-L' + libocm3LibPath2,
#               '-l' + libocm3cputype,

                   '-fno-use-cxa-atexit',
                  ]

subdir('lib')

p = ['fastusbaspv2', srcfiles, stm32f4cargs, stm32f4linkargs]

exe = executable(p[0], p[1],
                 cpp_args: p[2],
                 link_args: p[3],
                 include_directories : libocm3_incdir,
                 dependencies: [libocm3lib_dep],
                 link_with: [foolib],
                 build_by_default: true)

run_target('hex', command: [objcopy, ['-Obinary', exe.full_path(),
           exe.full_path() + '.hex']], depends: exe)
run_target('bin', command: [objcopy, ['-Obinary', exe.full_path(),
           exe.full_path() + '.bin']], depends: exe)
run_target('size', command: [size, exe.full_path(), '-B'], depends: exe)

# STlink programmer related commands
run_target('probe', command: [stinfo, '--probe'])
run_target('upload', command: [stflash, 'write', exe.full_path() + '.hex', '0x08000000'], depends: exe)
run_target('flash', command: [stm32flash, '-w', exe.full_path() + '.hex', '-b 115200', '/dev/ttyUSB0'], depends: exe)

if meson.is_cross_build()
   message('cross compiling for ' + cputype)
   message('''
            ninja - generates elf file.
            ninja hex - generates hex file.
            ninja bin - generates bin file.
            ninja upload - upload hex file to stm32 via stlink programmer.
            ninja flash - upload hex file to stm32 via serial port with stm32flash.
            ninja probe - probe stlink programmer.
            (C) Amitesh Singh''')
endif


