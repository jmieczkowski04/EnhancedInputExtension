// Copyright 2023 (C) Jakub Mieczkowski. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedPlayerInput.h"
#include "InputChangeCallback.h"
#include "EnhancedPlayerInputExt.generated.h"


UCLASS(config = Input, transient)
class ENHANCEDINPUTEXTENSION_API UEnhancedExtPlayerInput : public UEnhancedPlayerInput
{
	GENERATED_BODY()

public:
	void BindInputChangeCallback(IInputChangeCallback* Callback);
	void RemoveInputChangeCallback(IInputChangeCallback* Callback);

	virtual bool InputKey(const FInputKeyParams& Params) override;
	
private:
	void NotifyInputChangeCallback();

	InputType CurrentInputType = InputType::None;
	TSet<IInputChangeCallback*> InputChangeCallbacks;
};