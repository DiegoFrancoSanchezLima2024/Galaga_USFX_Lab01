// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SquadBuilder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USquadBuilder : public UInterface
{
	GENERATED_BODY()
};

class GALAGA_USFX_L_API ISquadBuilder
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// Las funciones virtuales puras de Squad Members
	virtual void buildSquadron1() = 0;
	virtual void buildSquadron2() = 0;
	virtual void buildSquadron3() = 0;
	virtual void buildSquadron4() = 0;
	virtual void buildSquadron5() = 0;
	virtual void BuildMesh() = 0;
	virtual class ASquadron* GetSquadron() = 0;
};
