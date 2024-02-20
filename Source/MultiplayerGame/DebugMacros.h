#pragma once

#include "CoreMinimal.h"

#define LOG(Format, ...)  if (GEngine) { \
	FString Message = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, FString::Printf(TEXT("%s%s() : %s"), NETMODE_WORLD, FUNC_NAME, *Message)); \
	UE_LOG(LogTemp, Log, TEXT("[%s%s()] %s"), NETMODE_WORLD, FUNC_NAME, *Message);\
}

#define LOG_WARNING(Format, ...) if (GEngine) { \
	FString Message = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, FString::Printf(TEXT("%s%s() : %s"), NETMODE_WORLD, FUNC_NAME, *Message)); \
	UE_LOG(LogTemp, Warning, TEXT("[%s%s()] %s"), NETMODE_WORLD, FUNC_NAME, *Message); \
}

#define LOG_SUCCESS(Format, ...) if (GEngine) { \
	FString Message = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("%s%s() : %s"), NETMODE_WORLD, FUNC_NAME, *Message)); \
	UE_LOG(LogTemp, Log, TEXT("[%s%s()] %s"), NETMODE_WORLD, FUNC_NAME, *Message); \
}

#define LOG_ERROR(Format, ...) if (GEngine) { \
	FString Message = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("%s%s() : %s"), NETMODE_WORLD, FUNC_NAME, *Message)); \
	UE_LOG(LogTemp, Error, TEXT("[%s%s()] %s"), NETMODE_WORLD, FUNC_NAME, *Message); \
}


#define NETMODE_WORLD (((GEngine == nullptr) || (GetWorld() == nullptr)) ? TEXT("") \
: (GEngine->GetNetMode(GetWorld()) == NM_Client) ? TEXT("[Client] ") \
: (GEngine->GetNetMode(GetWorld()) == NM_ListenServer) ? TEXT("[ListenServer] ") \
: (GEngine->GetNetMode(GetWorld()) == NM_DedicatedServer) ? TEXT("[DedicatedServer] ") \
: TEXT("[Standalone] "))

#if _MSC_VER
#define FUNC_NAME    TEXT(__FUNCTION__)
#else // FIXME - GCC?
#define FUNC_NAME    TEXT(__func__)
#endif
