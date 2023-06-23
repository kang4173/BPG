// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "BPG/SkillStruct.h"

#include "SkillComp.generated.h"


UCLASS(Blueprintable, BlueprintType)
class BPG_API USkillComp : public UActorComponent
{
	GENERATED_BODY()
		
public:	
	// Sets default values for this component's properties
	USkillComp();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Tbagging();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSkillStruct SKillST;
		
};
