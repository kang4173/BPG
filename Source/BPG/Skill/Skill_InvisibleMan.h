// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillComp.h"
#include "Skill_InvisibleMan.generated.h"

/**
 * 
 */
UCLASS()
class BPG_API USkill_InvisibleMan : public USkillComp
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:

	virtual void Tbagging() override;

	virtual void ActiveSkill() override;

};
