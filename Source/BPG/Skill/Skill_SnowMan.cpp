// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill_SnowMan.h"
#include "Kismet/GameplayStatics.h"
#include "BPG/SkillStruct.h"
#include "Components/BoxComponent.h"

USkill_SnowMan::USkill_SnowMan()
{
    UBoxComponent* BoxComponent = NewObject<UBoxComponent>();
}

void USkill_SnowMan::BeginPlay()
{
    Super::BeginPlay();

}

void USkill_SnowMan::TickComponent(float DeltaTime , ELevelTick TickType , FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime , TickType , ThisTickFunction);
}

void USkill_SnowMan::Tbagging()
{

    
    if (T_Num == 0)
    {
        Char->SetActorScale3D(FVector(1,1,0.1));
        T_Num++;
    }
    if (T_Num == 1)
    {
        Char->SetActorScale3D(FVector(1 , 1 , 1));
        T_Num = 0;
    }
    
}

void USkill_SnowMan::ActiveSkill()
{
    //SKillST.SkillRadius

    

}

void USkill_SnowMan::CharacterCall(ACharacter* OwnChar)
{
    Char = Cast<ABaseChar>(OwnChar); 
    //if (Char)
    //{
    //    SpaawnBox();
    //}
}

void USkill_SnowMan::SpaawnBox()
{

    //UBoxComponent* BoxComponent = NewObject<UBoxComponent>();

    

}
