// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"


#include "SkillStruct.generated.h"

/**
 * 
 */
USTRUCT(Atomic, BlueprintType)
struct FSkillStruct : public FTableRowBase
{
public:
	GENERATED_USTRUCT_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Power;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector SkillRadius;
	
};