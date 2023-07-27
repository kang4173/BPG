// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill_JetMan.h"
#include "Kismet/GameplayStatics.h"

USkill_JetMan::USkill_JetMan()
{
    
}

USkill_JetMan::~USkill_JetMan()
{
    //FVector ActorLoaction = Char->GetActorLocation();
    //Char->SetActorLocation(FVector(ActorLoaction.X , ActorLoaction.Y , ActorLoaction.Z - 1000));

}

void USkill_JetMan::BeginPlay()
{
    Super::BeginPlay();

    //Char->sphere->SetSimulatePhysics(false);
    //FVector ActorLoaction=Char->GetActorLocation();
    //Char->SetActorLocation(FVector(ActorLoaction.X, ActorLoaction.Y, ActorLoaction.Z+10));
}

void USkill_JetMan::TickComponent(float DeltaTime , ELevelTick TickType , FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime , TickType , ThisTickFunction);
}

void USkill_JetMan::Tbagging()
{


    if (T_Num == 0)
    {
        Char->SetActorScale3D(FVector(1 , 1 , 0.1));
        T_Num++;
    }
    if (T_Num == 1)
    {
        Char->SetActorScale3D(FVector(1 , 1 , 1));
        T_Num = 0;
    }

}

void USkill_JetMan::ActiveSkill()
{
    AMissile* Missile = GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(Char->GetActorLocation()) , Char->GetActorRotation());
    SetOwner(Missile);
   
}

void USkill_JetMan::CharacterCall(ACharacter* OwnChar)
{
    Char = Cast<ABaseChar>(OwnChar);
    ComSetting();

}

void USkill_JetMan::SetOwner(AMissile* misssile)
{
    misssile->Owner = Char;
}



void USkill_JetMan::ComSetting_Implementation()
{
    FVector ActorLoaction=Char->GetActorLocation();
    Char->SetActorLocation(FVector(ActorLoaction.X, ActorLoaction.Y, ActorLoaction.Z+1000));
  
    
}

