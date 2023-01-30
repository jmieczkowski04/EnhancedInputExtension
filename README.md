# Enhanced Input plugin extension

Simple extension to Enhanced Input plugin for Unreal&reg; Engine. Provides API to get notifcation on "Input Type" change. Currently, it only supports changing Keyboard+Mouse/Gamepad due to the popularity of these settings on PC, but you can modify the code to handle more inpu types. 

## How it works?

Plugin overrides UEnhancedPlayerInput class by adding API to bind callbacks and additionaly checks for input change in `bool InputChange(const FInputKeyParams& Params)`. 

## How to use?

Just add this plugin and Enhanced Input plugin to your project and after building source files in project settings set default Player Input class to `EnhancedExtPlayerInput`. 

To access API in C++ code, add "EnhancedInputExtension" in your .Build.cs file as module dependency. Then class that should recive callback must implement `IInputChangeCallback` interface and call `UEnhancedExtPlayerInput::BindInputChangeCallback` with pointer to callback class.
If you want to remove class from reciving a callback, call the similar method `UEnhancedExtPlayerInput::RemoveInputChangeCallback`. 

When input change occurs, this plugin calls `OnInputChange` method from `IInputChangeCallback` with new `InputType` argument. `InputType` is UENUM containging three entries: `None`, `KeyboardMouse` and `Gamepad`. Before engine recives any input, the default input type is `None`.

Blueprint support is not planned. 

## Feature

Currently, I have no plans to extend this plugin. It was designed as a demo and it should not be used in non-indie projects. If you have large enought team and are shipping for more than one platform, consider creating an internal stable release of CommonUI plugin, which is still experimental for now. If CommonUI plugin is still not stable enought for you and you need solution asap, feel free to ship with it. 