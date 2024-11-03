// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SCBaseTask.generated.h"

class USCBaseTask;

USTRUCT(BlueprintType)
struct FTaskInfo
{
	GENERATED_BODY()

	/** Tablet task info.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ShortTaskDescription;

	/** Billboard task info.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText TaskDescription;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTaskFinished);

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class SECONDCHARACTER_API USCBaseTask : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnTaskFinished OnTaskFinished;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	FText GetDescription();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void StartTask();

protected:
	UFUNCTION(BlueprintCallable, meta=(DeterminesOutputType="Class"))
	AActor* GetActorOfClass(const TSubclassOf<AActor> Class);

	UFUNCTION(BlueprintCallable, meta=(DeterminesOutputType="Class"))
	TArray<AActor*> GetAllActorsOfClass(const TSubclassOf<AActor> Class);

	UFUNCTION(BlueprintCallable)
	TArray<AActor*> GetAllActorsWithTag(const FName Tag);
};
