// Fill out your copyright notice in the Description page of Project Settings.


#include "UFOCylinder.h"

// Sets default values
AUFOCylinder::AUFOCylinder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Cylinder = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cylinder"));
	RootComponent = Cylinder;

	ConstructorHelpers::FObjectFinder<UStaticMesh>SM_Cylinder(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	if (SM_Cylinder.Succeeded())
	{
		Cylinder->SetStaticMesh(SM_Cylinder.Object);
	}


}

// Called when the game starts or when spawned
void AUFOCylinder::BeginPlay()
{
	Super::BeginPlay();
	



}

// Called every frame
void AUFOCylinder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

