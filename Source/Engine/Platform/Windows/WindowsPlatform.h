// Copyright (c) Wojciech Figat. All rights reserved.

#pragma once

#if PLATFORM_WINDOWS

#include "Engine/Platform/Win32/Win32Platform.h"

/// <summary>
/// The Windows platform implementation and application management utilities.
/// </summary>
class FLAXENGINE_API WindowsPlatform : public Win32Platform
{
public:

    /// <summary>
    /// Win32 application windows class name.
    /// </summary>
    static const Char* ApplicationWindowClass;

    /// <summary>
    /// Handle to Win32 application instance.
    /// </summary>
    static void* Instance;

    // Native exceptions handling function.
    static long __stdcall SehExceptionHandler(struct _EXCEPTION_POINTERS* ep);

public:

    /// <summary>
    /// Creates the system-wide mutex.
    /// </summary>
    /// <param name="name">The name of the mutex.</param>
    /// <returns>True if mutex already exists, otherwise false.</returns>
    static bool CreateMutex(const Char* name);

    /// <summary>
    /// Releases the mutex.
    /// </summary>
    static void ReleaseMutex();

    /// <summary>
    /// Pre initialize platform.
    /// </summary>
    /// <param name="hInstance">The Win32 application instance.</param>
    static void PreInit(void* hInstance);

    /// <summary>
    /// Returns true if current OS version is Windows 10.
    /// </summary>
    /// <returns>True if running on Windows 10 or later, otherwise false.</returns>
    static bool IsWindows10();

    static bool ReadRegValue(void* root, const String& key, const String& name, String* result);

public:

    // [Win32Platform]
    static bool Init();
    static void LogInfo();
    static void Tick();
    static void BeforeExit();
    static void Exit();
#if !BUILD_RELEASE
    static void Log(const StringView& msg);
    static bool IsDebuggerPresent();
#endif
    static void SetHighDpiAwarenessEnabled(bool enable);
    static String GetSystemName();
    static Version GetSystemVersion();
    static BatteryInfo GetBatteryInfo();
    static int32 GetDpi();
    static String GetUserLocaleName();
    static String GetComputerName();
    static bool GetHasFocus();
    static bool CanOpenUrl(const StringView& url);
    static void OpenUrl(const StringView& url);
    static Float2 GetMousePosition();
    static void SetMousePosition(const Float2& pos);
    static Rectangle GetMonitorBounds(const Float2& screenPos);
    static Float2 GetDesktopSize();
    static Rectangle GetVirtualDesktopBounds();
    static void GetEnvironmentVariables(Dictionary<String, String, HeapAllocation>& result);
    static bool GetEnvironmentVariable(const String& name, String& value);
    static bool SetEnvironmentVariable(const String& name, const String& value);
    static int32 CreateProcess(CreateProcessSettings& settings);
    static Window* CreateWindow(const CreateWindowSettings& settings);
    static void* LoadLibrary(const Char* filename);
#if CRASH_LOG_ENABLE
    static Array<StackFrame, HeapAllocation> GetStackFrames(int32 skipCount = 0, int32 maxDepth = 60, void* context = nullptr);
    static void CollectCrashData(const String& crashDataFolder, void* context = nullptr);
#endif
};

#endif
