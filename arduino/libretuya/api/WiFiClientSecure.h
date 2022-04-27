/*
  WiFiClientSecure.h - Base class that provides Client SSL to ESP32
  Copyright (c) 2011 Adrian McEwen.  All right reserved.
  Additions Copyright (C) 2017 Evandro Luis Copercini.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#pragma once

#include <Arduino.h>

#include "WiFi.h"

class IWiFiClientSecure : public IWiFiClient {
  public:
	int connect(IPAddress ip, uint16_t port, const char *rootCABuff, const char *cli_cert, const char *cli_key);
	int connect(const char *host, uint16_t port, const char *rootCABuff, const char *cli_cert, const char *cli_key);
	int connect(IPAddress ip, uint16_t port, const char *pskIdent, const char *psKey);
	int connect(const char *host, uint16_t port, const char *pskIdent, const char *psKey);

	int lastError(char *buf, const size_t size);
	void setInsecure(); // Don't validate the chain, just accept whatever is given. VERY INSECURE!
	void setPreSharedKey(const char *pskIdent, const char *psKey); // psKey in Hex
	void setCACert(const char *rootCA);
	void setCertificate(const char *client_ca);
	void setPrivateKey(const char *private_key);
	bool loadCACert(Stream &stream, size_t size);
	bool loadCertificate(Stream &stream, size_t size);
	bool loadPrivateKey(Stream &stream, size_t size);
	bool verify(const char *fingerprint, const char *domain_name);
	void setHandshakeTimeout(unsigned long handshake_timeout);

	WiFiClientSecure &operator=(const WiFiClientSecure &other);

	bool operator==(const bool value) {
		return bool() == value;
	}

	bool operator!=(const bool value) {
		return bool() != value;
	}

	bool operator==(const WiFiClientSecure &);

	bool operator!=(const WiFiClientSecure &rhs) {
		return !this->operator==(rhs);
	};

	using Print::write;
};