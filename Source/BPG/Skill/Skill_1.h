// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillComp.h"

#include "Skill_1.generated.h"

/**
 * 
 */
UCLASS()
class BPG_API USkill_1 : public USkillComp
{
	GENERATED_BODY()

public:
	USkill_1();
protected:
	virtual void BeginPlay() override;

public:

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:


};
