#pragma once

// Copyright 2014 Stellar Development Foundation and contributors. Licensed
// under the Apache License, Version 2.0. See the COPYING file at the root
// of this distribution or at http://www.apache.org/licenses/LICENSE-2.0

#include "generated/Stellar-types.h"

namespace stellar
{

using xdr::operator==;

class ByteSlice;

class SecretKey
{
    CryptoKeyTypes mKeyType;
    uint512 mSecretKey;

  public:
    SecretKey();

    // Get the public key portion of this secret key.
    PublicKey getPublicKey() const;

    // Get the seed portion of this secret key.
    uint256 getSeed() const;

    // Get the seed portion of this secret key as as Base58Check string.
    std::string getBase58Seed() const;

    // Get the public key portion of this secret key as as Base58Check string.
    std::string getBase58Public() const;

    // Return true iff this key is all-zero.
    bool isZero() const;

    // Produce a signature of `bin` using this secret key.
    uint512 sign(ByteSlice const& bin) const;

    // Create a new, random secret key.
    static SecretKey random();

    // Decode a secret key from a provided Base58Check seed value.
    static SecretKey fromBase58Seed(std::string const& base58Seed);

    // Decode a secret key from a binary seed value.
    static SecretKey fromSeed(uint256 const& seed);

    bool operator==(SecretKey const& rh)
    {
        return (mKeyType == rh.mKeyType) && (mSecretKey == rh.mSecretKey);
    }
};

// public key utility functions
namespace PubKeyUtils
{
// Return true iff `signature` is valid for `bin` under `key`.
bool verifySig(PublicKey const& key, uint512 const& signature,
               ByteSlice const& bin);

std::string toShortString(PublicKey const& pk);

std::string toBase58(PublicKey const& pk);

PublicKey fromBase58(std::string const& s);
}
}
