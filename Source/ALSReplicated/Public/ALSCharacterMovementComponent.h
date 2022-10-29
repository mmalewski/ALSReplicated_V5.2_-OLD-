// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Net/UnrealNetwork.h"
#include "ALSCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class ALSREPLICATED_API UALSCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable, Category="Movement Component")
	void SetMaxWalkSpeed(float Max_WalkSpeed);

	UFUNCTION(BlueprintCallable, Category="Movement Component")
	void SetMaxWalkSpeedCrounched(float Max_WalkSpeedCrounched);

	UFUNCTION(BlueprintCallable, Category="Movement Component")
	void SetMaxAcceleration(float Max_Acceleration);
	
	UFUNCTION(BlueprintCallable, Category="Movement Component")
    void SetBrakingDecelerationWalking(float Braking_DecelerationWalking);
    	
	UFUNCTION(BlueprintCallable, Category="Movement Component")
	void SetGroundFriction(float Ground_Friction);

	UFUNCTION(BlueprintCallable, Category="Movement Component")
	void SetBrakingFricktionFactor(float Braking_FricktionFactor);
	
private:
	UPROPERTY()
	float NewMaxWalkSpeed = MaxWalkSpeed;
	
	UPROPERTY()
	float NewMaxWalkSpeedCrounched = MaxWalkSpeedCrouched;

	UPROPERTY()
	float NewMaxAcceleration = MaxAcceleration;

	UPROPERTY()
	float NewBrakingDecelerationWalking = BrakingDecelerationWalking;
	
	UPROPERTY()
    float NewGroundFriction = GroundFriction;

	UPROPERTY()
	float NewBrakingFricktionFactor = BrakingFrictionFactor;

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_MaxWalkSpeed(float Max_WalkSpeed);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_MaxWalkSpeedCrounched(float Max_WalkSpeedCrounched);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_MaxAcceleration(float Max_Acceleration);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_BrakingDecelerationWalking(float Braking_DecelerationWalking);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_GroundFriction(float Ground_Friction);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_BrakingFricktionFactor(float Braking_FricktionFactor);
	
};
