// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill_ReturnMan.h"

USkill_ReturnMan::USkill_ReturnMan()
{
    PrimaryComponentTick.bCanEverTick = true;

}

void USkill_ReturnMan::BeginPlay()
{
    Super::BeginPlay();

}

void USkill_ReturnMan::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USkill_ReturnMan::Tbagging()
{
}

void USkill_ReturnMan::ActiveSkill()
{

    FVector MeshLoc = CheckPoint->Mesh->GetComponentLocation();
    FVector CharLoc = Char->GetActorLocation();
  //  Char->AddActorLocalOffset(MeshLoc - CharLoc);
    float Distance = FVector::DistSquared(MeshLoc, CharLoc);

    FVector NewLocation = FMath::Lerp(MeshLoc, CharLoc, 1);
    Char->SetActorLocation(NewLocation);
}
  

void USkill_ReturnMan::FindPoint(AActor* Point)
{
    CheckPoint = Cast<AChangePoint>(Point);
    if(CheckPoint)
    {
        GetWorld()->GetTimerManager().SetTimer(Timer, this, &USkill_ReturnMan::ActiveSkill, 1.0f, true);
    }
}

void USkill_ReturnMan::CharacterCall(ACharacter* OwnChar)
{
    Char = Cast<ABaseChar>(OwnChar);

}
