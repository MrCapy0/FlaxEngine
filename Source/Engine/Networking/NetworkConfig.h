﻿// Copyright (c) 2012-2021 Wojciech Figat. All rights reserved.

#pragma once

#include "Engine/Platform/Network.h"

API_ENUM(Namespace="FlaxEngine.Networking") enum class NetworkTransportType
{
    Undefined = 0,
    
    ENet
};

API_STRUCT(Namespace="FlaxEngine.Networking") struct FLAXENGINE_API NetworkConfig
{
DECLARE_SCRIPTING_TYPE_MINIMAL(NetworkConfig);
public:
    API_FIELD()
    NetworkTransportType NetworkDriverType = NetworkTransportType::ENet;
    // TODO: Expose INetworkDriver as a ref not enum, when C++/C# interfaces are done.

public:
    API_FIELD()
    uint16 ConnectionsLimit = 32;

    /// <summary>
    /// Address used to connect to or listen at.
    /// Set it to "any" when you want to listen at all available addresses.
    /// </summary>
    /// <remarks>Only IPv4 is supported.</remarks>
    API_FIELD()
    String Address = String("127.0.0.1");

    /// <summary>
    /// The port to connect to or listen at.
    /// </summary>
    API_FIELD()
    uint16 Port = 7777;
    
    API_FIELD()
    uint16 MessageSize = 1500; // MTU
    
    API_FIELD()
    uint16 MessagePoolSize = 2048; // (RX and TX)
};
