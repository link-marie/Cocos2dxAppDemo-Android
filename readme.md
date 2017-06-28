# Cocos2d-x Framework Project for Android for Beginners

This project is a framework of [Cocos2d-x](http://www.cocos2d-x.org/) application to make an application easily.

You can use this framework to make your application to start with.

[![Play Store Badge](https://developer.android.com/images/brand/en_app_rgb_wo_60.png)](https://play.google.com/store/apps/details?id=com.linknext.cocos2dx)

[Greatworks](https://play.google.com/store/apps/details?id=com.linknext.cocos2dx)


# Features
- Cocos2d-x development base framework
- Multiple screen resolution support
- Device back key support

# What you can learn with the source codes
- Usage of image handling
- Event handling
- Atlas loader example
- JNI (Java - C++ interface) examples
- Easy logging macros
- Layer background color
- Understanding of screen size and visible size of multi resolution
- Font usage
- Multi-byte character usage
- Enabling Android back-key handling



# Environments
This project is made with:

- [Cocos2d-x 3.15.1](http://www.cocos2d-x.org/)
- [Android Studio 2.3.3](https://developer.android.com/studio/index.html)
- [Android NDK 15.1.4119039](https://developer.android.com/ndk/index.html)
- [Android SDK Build Tool 25.0.3](https://developer.android.com/studio/index.html)
- [Ubuntu 16.04](https://www.ubuntu.com/)

# Project Structure

*AppDemo* - The project root<br>

*Classes* - C++ source codes and header files<br>

*Dev* - Development resources such as image vector files<br>

*Resources*<br>
&nbsp;&nbsp;&nbsp;&nbsp;*fonts* - font files<br>
&nbsp;&nbsp;&nbsp;&nbsp;*hd* - images for high resolution<br>
&nbsp;&nbsp;&nbsp;&nbsp;*images* - images for both high and small<br>
&nbsp;&nbsp;&nbsp;&nbsp;*sd* - images for small resolution<br>

*cocos2d* - cocos2d-x source and header files<br>

*proj.android* - project definition for Eclipse<br>

*proj.android-studio* - project definition for Android  Studio<br>

&nbsp;&nbsp;&nbsp;&nbsp;build.gradle - build setting for project<br>
&nbsp;&nbsp;&nbsp;&nbsp;gradle.properties - build parameters for project<br>
&nbsp;&nbsp;&nbsp;&nbsp;readme.md - this file<br>
&nbsp;&nbsp;&nbsp;&nbsp;settings.gradle - definitions of project modules<br>

&nbsp;&nbsp;&nbsp;&nbsp;*app* - application folder<br>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;build.gradle - build setting for application<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;AndroidManifest.xml - Android manifest file

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*jni*<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Android.mk - definition of C++ source codes and build parameters<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Application.mk - C++ parameters for compiling<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*res* - resources for Java<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*src* - Java source codes<br>


# Setup

## OS Environment
### Path setting
Add following directory to PATH environment
- /home/[User]/cocos2d-x-3.xx
- /home/[User]/cocos2d-x-3.xx/templates
- /home/[User]/cocos2d-x-3.xx/tools/cocos2d-console/bin

### Cocos2d-x environments
- COCOS_X_ROOT=/home/[User]/cocos2d-x-3.xx/
- COCOS_CONSOLE_ROOT=/home/[User]/cocos2d-x-3.xx/tools/cocos2d-console/bin
- COCOS_TEMPLATES_ROOT=/home/[User]/cocos2d-x-3.xx/templates

## Android environments
- ANDROID_NDK_ROOT=/home/[User]/android-sdk/ndk-bundle
- ANDROID_NDK="$ANDROID_NDK_ROOT"
- NDK_ROOT="$ANDROID_NDK_ROOT"
- ANDROID_SDK_ROOT=/home/[User]/android-sdk
- ANDROID_HOME="$ANDROID_SDK_ROOT"
- ANDROID_SDK_HOME="$ANDROID_SDK_ROOT"


# Build
## Simplest way

Just download master project and build with Android Studio

## Command Line

Suppose *AppDemo* project is located at 
  /home/[User]/cocos2d-x-3.15.1/Projects/

Execute following command on Terminal for debug build

    cocos compile -s /home/[User]/cocos2d-x-3.15.1/Projects/AppDemo -m debug -p android -p android --android-studio --ap android-16

Chose suitable SDK version by specifying argument
    
    --ap android-xx
    
For release build use the following command

    cocos compile -s /home/[User]/cocos2d-x-3.15.1/Projects/AppDemo -m release -p android -p android --android-studio --ap android-16


# Detail

## Set Android SDK version manually

In *gradle.properties*, set suitable Android SDK version

    PROP_TARGET_SDK_VERSION=16

## Set Android ABI (Application Binary Interface) manually 
In *gradle.properties*, set suitable ABI for target devices

    PROP_APP_ABI := armeabi:armeabi-v7a:x86
    
- armeabi - somewhat older devices
- armeabi-v7a - currently most popular abi
- x86 - for x86 or IA-32 instruction set of the CPU. it can be used for [Genymotion](https://www.genymotion.com/) emulator.



## How to change cocos library name

The default name of cocos library is 'MyGame'.
If you want to change the name, modify following files.

- AndroidManifest.xml
```XML
     <meta-data android:name="android.app.lib_name" android:value="NewName" />
```


- Android.mk

```Make
    LOCAL_MODULE := NewName_shared
```

```Make
    LOCAL_MODULE_FILENAME := libNewName
```

- build.gradle (for project)

```gradle
    targets 'NewName'
```

# Acknowledgement
- [Cocos2d-x](http://www.cocos2d-x.org/)


# Developed By
Marie Rijk <rijkmarie@gmail.com>
with our members ...

# License

    Copyright Marie Rijk since 2017

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.

