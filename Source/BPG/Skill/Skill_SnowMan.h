// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillComp.h"
#include "BPG/BaseChar.h"
#include "Skill_SnowMan.generated.h"

/**
 * 
 */
UCLASS()
class BPG_API USkill_SnowMan : public USkillComp
{
	GENERATED_BODY()
public:
		USkill_SnowMan();
protected:
	virtual void BeginPlay() override;

public:

	virtual void TickComponent(float DeltaTime , ELevelTick TickType , FActorComponentTickFunction* ThisTickFunction) override;

public:

	virtual void Tbagging() override;

	virtual void ActiveSkill() override;

	virtual void CharacterCall(ACharacter* OwnChar) override;

public:

	
	int T_Num = 0;
	ABaseChar* Char;



	//UPROPERTY(EditAnywhere , BlueprintReadWrite)
	//FBox* ExSpawnBox;


	void SpaawnBox();
};
