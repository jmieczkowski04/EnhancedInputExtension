// Copyright 2023 (C) Jakub Mieczkowski. All rights reserved.


#include "EnhancedPlayerInputExt.h"

void UEnhancedExtPlayerInput::BindInputChangeCallback(IInputChangeCallback* Callback)
{
	InputChangeCallbacks.Emplace(Callback);
}

void UEnhancedExtPlayerInput::RemoveInputChangeCallback(IInputChangeCallback* Callback)
{
	InputChangeCallbacks.Remove(Callback);
}

void UEnhancedExtPlayerInput::NotifyInputChangeCallback()
{
	for (auto& Elem : InputChangeCallbacks)
	{
		Elem->OnInputChange(CurrentInputType);
	}
}

bool UEnhancedExtPlayerInput::InputKey(const FInputKeyParams& Params)
{
	bool bResult = Super::InputKey(Params);
	bool bIsGamepad = Params.bIsGamepadOverride;
	if (bIsGamepad)
	{
		if (CurrentInputType != InputType::Gamepad)
		{
			CurrentInputType = InputType::Gamepad;
			NotifyInputChangeCallback();
		}
	}
	else
	{
		if (CurrentInputType != InputType::KeyboardMouse)
		{
			CurrentInputType = InputType::KeyboardMouse;
			NotifyInputChangeCallback();
		}
	}

	return bResult;
}