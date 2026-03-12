// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LearnCppActor.generated.h"

UCLASS()
class LEARNINGCPP_API ALearnCppActor : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, Category="Assignment")
	int32 PrintPrimedNumberTill = 15;
	// Sets default values for this actor's properties
	UPROPERTY(EditAnywhere, Category = "Assignment")
	int32 PrintFibonacciTill = 15;
	
	ALearnCppActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
