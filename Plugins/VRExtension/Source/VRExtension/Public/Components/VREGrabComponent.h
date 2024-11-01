// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "VREGrabComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGrabbed, UPrimitiveComponent*, GrabbedComp, UPrimitiveComponent*,
                                             ParentComp);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnReleased, UPrimitiveComponent*, ReleasedComp, UPrimitiveComponent*,
                                             ParentComp);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class VREXTENSION_API UVREGrabComponent : public UPhysicsConstraintComponent
{
	GENERATED_BODY()

public:
	UVREGrabComponent();

	UPROPERTY(BlueprintAssignable)
	FOnGrabbed OnGrabbed;

	UPROPERTY(BlueprintAssignable)
	FOnReleased OnReleased;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	uint8 bIsParent : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float GrabRadius = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 bFreeGrab : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TEnumAsByte<EObjectTypeQuery>> GrabObjectTypes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName SelfBoneName = FName();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName GrabTag = FName(TEXT("grab"));

	UFUNCTION(BlueprintCallable)
	bool TryGrab(const bool bDebug = false);

	UFUNCTION(BlueprintCallable)
	bool TryRelease();

	UFUNCTION(BlueprintPure)
	bool IsHeld() const { return ConstraintInstance.IsValidConstraintInstance(); }

	UFUNCTION(BlueprintPure)
	UPrimitiveComponent* GetHeldComponent();

	UFUNCTION(BlueprintPure)
	UPrimitiveComponent* GetParentComponent();

private:
	FHitResult FindGrabObject(const bool bDebug = false) const;
	void ConnectComponents(UPrimitiveComponent* OtherComp, const FName& BoneName = FName());
};
