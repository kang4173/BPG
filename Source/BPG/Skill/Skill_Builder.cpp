// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill_Builder.h"
#include "Kismet/GameplayStatics.h"



USkill_Builder::USkill_Builder()
{
    
}

void USkill_Builder::BeginPlay()
{
    Super::BeginPlay();

}

void USkill_Builder::TickComponent(float DeltaTime , ELevelTick TickType , FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime , TickType , ThisTickFunction);
}

void USkill_Builder::Tbagging()
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

void USkill_Builder::ActiveSkill()
{

    AAttackTower* tower = GetWorld()->SpawnActor<AAttackTower>(AAttackTower::StaticClass() , FVector(Char->GetActorLocation().X, Char->GetActorLocation().Y, Char->GetActorLocation().Z-90) , Char->GetActorRotation());
    SetOwner(tower);
}

void USkill_Builder::CharacterCall(ACharacter* OwnChar)
{
    Char = Cast<ABaseChar>(OwnChar);
    
}

void USkill_Builder::SetOwner(AAttackTower* Attacktower)
{
    Attacktower->Owner= Char;
}
