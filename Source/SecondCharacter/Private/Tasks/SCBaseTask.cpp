// Fill out your copyright notice in the Description page of Project Settings.


#include "SecondCharacter/Public/Tasks/SCBaseTask.h"

#include "Kismet/GameplayStatics.h"

FText USCBaseTask::GetDescription_Implementation()
{
	return FText::FromString(TEXT("Base task description."));
}

AActor* USCBaseTask::GetActorOfClass(const TSubclassOf<AActor> Class)
{
	return UGameplayStatics::GetActorOfClass(this, Class);
}

TArray<AActor*> USCBaseTask::GetAllActorsOfClass(const TSubclassOf<AActor> Class)
{
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(this, Class, Actors);

	return Actors;
}

TArray<AActor*> USCBaseTask::GetAllActorsWithTag(const FName Tag)
{
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsWithTag(this, Tag, Actors);

	return Actors;
}
