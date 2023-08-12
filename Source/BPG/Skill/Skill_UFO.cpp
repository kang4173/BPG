// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill_UFO.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"

USkill_UFO::USkill_UFO()
{
}

void USkill_UFO::BeginPlay()
{
    Super::BeginPlay();
    GEngine->AddOnScreenDebugMessage(-1, 30, FColor::Green, TEXT("UFO Beginplay"));
}
    

void USkill_UFO::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USkill_UFO::Tbagging()
{

}

void USkill_UFO::ActiveSkill()
{
    GetWorld()->SpawnActor<AUFOCylinder*>(CylinderClass, Char->GetActorLocation(), Char->GetActorRotation());
}

void USkill_UFO::Released_ActiveSkill()
{
   
}

void USkill_UFO::CharacterCall(ACharacter* OwnChar)
{
    Char = Cast<ABaseChar>(OwnChar);
    ComSetting();
}

void USkill_UFO::ComSetting_Implementation()
{
    FVector ActorLoaction = Char->GetActorLocation();
    Char->SetActorLocation(FVector(ActorLoaction.X, ActorLoaction.Y, ActorLoaction.Z + 1000));
    UCharacterMovementComponent* CharMovement = Char->GetCharacterMovement();
    CharMovement->GravityScale = 0;
    CharMovement->MaxAcceleration = 15000.0f;
    CharMovement->bUseSeparateBrakingFriction = true;
    CharMovement->BrakingFriction = 10000;
}
