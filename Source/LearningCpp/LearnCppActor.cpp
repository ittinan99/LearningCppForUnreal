// Fill out your copyright notice in the Description page of Project Settings.


#include "LearnCppActor.h"

void ALearnCppActor::PrintPrimedNumberTillFunction()
{
	bool IsPrimed = false;
	for (int32 i(2); i < PrintPrimedNumberTill; ++i)
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
}

void ALearnCppActor::PrintFibonacciTillFunction()
{
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

void ALearnCppActor::PrintHierarchyRecursiveFunction()
{
    struct FActorHierIterator
    {
        AActor* Actor = nullptr;
        int32 Depth = INDEX_NONE;

        FActorHierIterator GetNextDepth(AActor* CurrentActor, int32 InDepth)
        {
            Actor = CurrentActor;
            Depth = InDepth;

			if (!Actor)
			{
				return *this;
			}

            FString Indent = "";
            for (int32 i = 0; i < Depth; ++i)
            {
                Indent += "    ";
            }

            UE_LOG(LogTemp, Log, TEXT("%s%s"), *Indent, *Actor->GetActorLabel());

            TArray<AActor*> AttachedActors;
            Actor->GetAttachedActors(AttachedActors);

            for (AActor* Child : AttachedActors)
            {
                FActorHierIterator ChildIter;
                ChildIter.GetNextDepth(Child, Depth + 1);
            }
            return *this;
        }
    };

    FActorHierIterator Hier;
    FActorHierIterator RootResult = Hier.GetNextDepth(this, 0);
}

void ALearnCppActor::PrintHierarchyFunction()
{
    struct FActorHierIterator
    {
        AActor* Actor = nullptr;
        int32   Depth = INDEX_NONE;
        int32   ChildIndex = 0;
        
		bool IsValid() const
		{
			return Actor != nullptr;
		}
        
        TArray<AActor*> GetChildren() const
        {
            TArray<AActor*> OutChildren;
            if (this->IsValid())
            {
                Actor->GetAttachedActors(OutChildren);
            }
            return OutChildren;
        }

        FActorHierIterator GetCurrentChild() const
        {
            TArray<AActor*> Children = GetChildren();
            if (!Children.IsValidIndex(ChildIndex))
            {
                return FActorHierIterator{};
            }

            FActorHierIterator Next;
            Next.Actor = Children[ChildIndex];
            Next.Depth = Depth + 1;
            Next.ChildIndex = 0;
            return Next;
        }
        
        bool HasMoreChildren() const
        {
            return GetChildren().IsValidIndex(ChildIndex);
        }
    };

    UE_LOG(LogTemp, Log, TEXT("%s"), *this->GetActorNameOrLabel());

    FActorHierIterator Root;
    Root.Actor = this;
    Root.Depth = 0;

    TArray<FActorHierIterator> Stack;
    Stack.Add(Root);
    
    while (Stack.Num() > 0)
    {
        FActorHierIterator& Current = Stack.Last();

        if (!Current.HasMoreChildren())
        {
            Stack.Pop(EAllowShrinking::No);
            continue;
        }

        FActorHierIterator Child = Current.GetCurrentChild();
        Current.ChildIndex++;

        UE_LOG(LogTemp, Log, TEXT("%*s%s"), Child.Depth * 2, TEXT(""), *Child.Actor->GetActorNameOrLabel());

        Stack.Push(Child);
    }
}

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

	//PrintPrimedNumberTillFunction();

	//UE_LOG(LogTemp, Log, TEXT("-----------------------"));

	//PrintFibonacciTillFunction();

	//UE_LOG(LogTemp, Log, TEXT("-----------------------"));

	PrintHierarchyFunction();
}

// Called every frame
void ALearnCppActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

