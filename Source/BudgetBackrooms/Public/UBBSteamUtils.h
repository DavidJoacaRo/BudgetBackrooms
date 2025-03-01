#pragma once

#include "OnlineSubsystemSteam.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CoreMinimal.h"
#include "ThirdParty/Steamworks/Steamv151/sdk/public/steam/steam_api.h"
#include "UBBSteamUtils.generated.h"



UENUM(BlueprintType)
enum class ESteamNotificationPosition : uint8
{
    TopLeft UMETA(DisplayName = "Top Left"),
    TopRight UMETA(DisplayName = "Top Right"),
    BottomLeft UMETA(DisplayName = "Bottom Left"),
    BottomRight UMETA(DisplayName = "Bottom Right")
};

UCLASS()
class BUDGETBACKROOMS_API UBBSteamUtils : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UBBSteamUtils();

    UFUNCTION(BlueprintCallable, Category = "Steam", meta = (Keywords = "Set Steam Rich Presence", ToolTip = "Sets Steam Rich Presence with the desired args. It can be seen from the Friends List or other menus in the Steam Community."))
    static void SetSteamRichPresence(const FString& Key, const FString& Value);

    UFUNCTION(BlueprintCallable, Category = "Steam", meta = (Keywords = "Steam Overlay Position", ToolTip = "Changes in which corner to show Steam Overlay notifications"))
    static void SetSteamOverlayNotificationPosition(ESteamNotificationPosition Position);

    UFUNCTION(BlueprintCallable, Category = "Steam", meta = (ToolTip = "Self-explanatory, toggles the Steam Overlay as if the user pressed SHIFT + TAB"))
    static void ToggleSteamOverlay();

    UFUNCTION(BlueprintCallable, Category = "Steam", meta = (Keywords = "Steam Connection", ToolTip = "Checks whether the player has Steam active, and if the game can do a handshake with the Steam API (aka Initialization)"))
    static void CheckSteamConnection(bool& bIsConnected);

    UFUNCTION(BlueprintCallable, Category = "Steam", meta = (Keywords = "Steam Overlay", ToolTip = "Self-explanatory; Opens the user's Steam Overlay with a defined target link."))
    static void OpenSteamOverlayWithURL(const FString& URL);

    UFUNCTION(BlueprintCallable, Category= "Steam", meta = (Keywords = "Verify Integrity", ToolTip = "Sends the Steam Client a request to verify the game's integrity, and if there's anything corrupt detected the bool will be set to true. Works only if the game's installed under Steam, Steam is open and the SteamSDK is integrated properly."))
    static void MarkContentCorrupt(bool& bMissingFilesOnly);

    

};
