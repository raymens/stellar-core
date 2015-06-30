// Copyright 2015 Stellar Development Foundation and contributors. Licensed
// under the Apache License, Version 2.0. See the COPYING file at the root
// of this distribution or at http://www.apache.org/licenses/LICENSE-2.0

namespace stellar
{

typedef opaque Hash[32];
typedef opaque uint256[32];

typedef opaque uint512[64];

typedef unsigned int uint32;
typedef int int32;

typedef unsigned hyper uint64;
typedef hyper int64;

enum CryptoKeyTypes
{
    KEY_TYPES_ED25519 = 0
};

union PublicKey switch (CryptoKeyTypes type)
{
case KEY_TYPES_ED25519:
    uint256 ed25519;
};

typedef PublicKey NodeID;
}
