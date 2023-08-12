// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/StaticMeshComponent.h"

#include "UFOCylinder.generated.h"

UCLASS()
class BPG_API AUFOCylinder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUFOCylinder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Cylinder;


};
