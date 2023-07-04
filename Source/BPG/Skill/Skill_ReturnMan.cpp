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

// box 에 오버랩 되지 않은상태로 실행 시 MeshLoc의 값은 제자리로 됨
void USkill_ReturnMan::ActiveSkill()
{
    Char->SetActorLocation(MeshLoc);
}
  

void USkill_ReturnMan::FindPoint(FVector Loc)
{
    MeshLoc = Loc;
    GetWorld()->GetTimerManager().SetTimer(Timer, this, &USkill_ReturnMan::ActiveSkill, DelayTime, true, DelayTime);
}

void USkill_ReturnMan::CharacterCall(ACharacter* OwnChar)
{
    Char = Cast<ABaseChar>(OwnChar);

}
