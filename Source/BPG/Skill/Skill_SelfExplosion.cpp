// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill_SelfExplosion.h"

#include "Kismet/GameplayStatics.h"

USkill_SelfExplosion::USkill_SelfExplosion()
{
    PrimaryComponentTick.bCanEverTick = true;

}

void USkill_SelfExplosion::BeginPlay()
{
    Super::BeginPlay();

}

void USkill_SelfExplosion::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USkill_SelfExplosion::Tbagging()
{
}

void USkill_SelfExplosion::ActiveSkill()
{
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseChar::StaticClass(), AllChar);

    for (int i = 0; i < AllChar.Num(); i++) // �ΰ��� ���� ĳ�� ���θ�
    {
        Char = Cast<ABaseChar>(AllChar[i]);
        
        Char->SetActorLocation(FVector((-1400, 1550, 108)));

        Char->ChangeChar();  // skill�� �����Ű�� �Լ�
    } 
   
}

void USkill_SelfExplosion::CharacterCall(ACharacter* OwnChar)
{
    Char = Cast<ABaseChar>(OwnChar); // ���⿡ �Ѱ��ְ� 


   
}


