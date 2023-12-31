// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillComp.h"

#include "BPG/BaseChar.h"

#include "Skill_FlashMan.generated.h"

/**
 * 
 */
UCLASS()
class BPG_API USkill_FlashMan : public USkillComp
{
	GENERATED_BODY()
	
public:
	USkill_FlashMan();
protected:
	virtual void BeginPlay() override;

public:

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:

	virtual void Tbagging() override;

	virtual void ActiveSkill() override;

	virtual void CharacterCall(ACharacter* OwnChar) override;

public:
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetCharSpeed();

public:

	UPROPERTY(BlueprintReadOnly)
	ABaseChar* Char;

};

