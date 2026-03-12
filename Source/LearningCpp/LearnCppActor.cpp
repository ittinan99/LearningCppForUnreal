// Fill out your copyright notice in the Description page of Project Settings.


#include "LearnCppActor.h"

// Sets default values
ALearnCppActor::ALearnCppActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALearnCppActor::BeginPlay()
{
	Super::BeginPlay();

	bool IsPrimed = false;
	for(int32 i(2); i < PrintPrimedNumberTill; ++i)
	{
		IsPrimed = true;
		for (int32 j(2); j < i; ++j)
			if (i % j == 0)
			{
				IsPrimed = false;
				break;
			}
		if (IsPrimed)
		{
			UE_LOG(LogTemp, Log, TEXT("%d"), i);
		}
	}

	UE_LOG(LogTemp, Log, TEXT("-----------------------"));

	int32 previous01 = 0;
	int32 previous02 = 1;
	for (int32 i(0); i < PrintFibonacciTill; ++i)
	{	
		if (i == 0 || i == 1)
		{
			UE_LOG(LogTemp, Log, TEXT("0"));
			continue;
		}

		int32 current = previous01 + previous02;
		previous02 = previous01;
		previous01 = current;

		UE_LOG(LogTemp, Log, TEXT("%d"), current);
	}
}

// Called every frame
void ALearnCppActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

