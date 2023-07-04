// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillComp.h"

#include "BPG/ChangePoint.h"
#include "BPG/BaseChar.h"

#include "Skill_SelfExplosion.generated.h"

/**
 * 
 */
UCLASS()
class BPG_API USkill_SelfExplosion : public USkillComp
{
	GENERATED_BODY()
	
public:
	USkill_SelfExplosion();
protected:
	virtual void BeginPlay() override;

public:

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:

	virtual void Tbagging() override;

	virtual void ActiveSkill() override;

	virtual void FindPoint(FVector Loc) override;

	virtual void CharacterCall(ACharacter* OwnChar) override;

public:

	TArray<AActor*> AllChar;

	AChangePoint* CheckPoint;

	ABaseChar* Char;

	FVector MeshLoc;
};
