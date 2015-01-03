# ARMstrap_CubeMX_Template
Base project for STM32CubeMX code generation for ARMstrap Eagle.
(Note: at time of writing, the only 'CubeMX file created was for
the STM32F427 variant of the 'Eagle. Your mileage may vary with
the other variants. I only have the 427 and so I'm not able to 
test on the other chips. Also, out of the box, STM32CubeMX only
runs on Windows.)

## Using this project
1. Download repository as zip (probably less messy than cloning)
2. Import as archived project into ARMstrap Eclipse workspace
3. Rename/copy template to the project name you want to use
4. Open the *ARMstrap Eagle 4x7.ioc* file with STM32CubeMX
   (assumes you've already downloaded it from STM and installed it)
5. Configure the peripherals, pins, clocks, and etc. The pins
   that are used on-board have already been pinned and named (and
   (you'll notice *(OB)* after the names of pins only routed
   on-board).

   These pinned pins will make peripherals blocked by them
   unavailable, so you can see what peripherals and modes you
   can actually use.

   The default configuration assumes that you
   will use the UART configuration for the FTDI pins and enable
   SPI3 on the pins connected to the on-board flash chip.
6. Once you're done configuring, click the generate code button.
   This will generate the initialization code for all of your
   configured peripherals. The code is generated into the *Inc*,
   *Src*, and *Drivers* directories.
7. Before the code will build, you need to select the platform
   in the CMSIS driver. Open the file `Drivers/ST/STM32F4xx/Include/stm32f4xx.h`
   and find the line that corresponds to your chip. I have the
   STM32F427, so I will change the line
   `/* #define STM32F427xx */  /*!< STM32F427VG, STM32F427VI, STM32F427ZG, STM32F427ZI, STM32F427IG and STM32F427II Devices */`
   to
   `#define STM32F427xx  /*!< STM32F427VG, STM32F427VI, STM32F427ZG, STM32F427ZI, STM32F427IG and STM32F427II Devices */`

   If you try to build before this, you'll get many, many errors.
   After uncommenting the appropriate line, you should be able
   to build successfully.

   If you've selected any of the middlewares, you'll likely need
   to add some additional paths to *Project Preferences > C/C++ General > Paths and Symbols > Includes*
   to get the code to build correctly. I haven't played with
   the middlewares enough to be able to set up default includes
   for them.
8. One thing I haven't figured out yet (not sure if it's even 
   possible) is to persist the debug configurations in the project. 
   They appear to be stored at the workspace level. So when you 
   import the project, it will not be set up to run. What I 
   recommend is to open one of the ARMstrap projects as well, then
   add the debug configuration by copying the settings from the
   existing project. 
9. Now you can do your work. 

   When editing the generated *main.c*,
   pay special attention to the generated comments. There are
   comments that delimit special sections for user code. If you
   keep your code confined to these sections (and generally you
   will have no problem doing so; there are sections in all the
   essential places), STM32CubeMX can keep your code when it runs
   code generation. 

   This will enable you to change the peripheral
   configuration after you've already started working, by making
   the changes in STM32CubeMX and regenerating. So, if you
   realized you need to enable an I2C port, change a UART baud
   rate, or whatever, you can do it.

   You can, of course, just change the code directly, but then
   the code will be out of sync with the Cube file, and you will
   lose your changes if you choose to generate code again from
   Cube and forget to replicate your changes first.

Good luck! Also check out [https://github.com/hossboss/ARMstrap_Modules](https://github.com/hossboss/ARMstrap_Modules)
for some modules I've created for use in this project structure.
