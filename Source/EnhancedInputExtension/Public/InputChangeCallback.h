// Copyright 2023 (C) Jakub Mieczkowski. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnhancedInputExtensionHelpers.h"
#include "InputChangeCallback.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInputChangeCallback : public UInterface
{
	GENERATED_BODY()
};

/**
 * Provides UObject ability to get callback on InpuType change
 */
class ENHANCEDINPUTEXTENSION_API IInputChangeCallback
{
	GENERATED_BODY()

public:
	virtual void OnInputChange(InputType Type) = 0;
};
