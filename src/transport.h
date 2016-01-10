/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_TRANSPORT_H
#define HHVM_GIT2_TRANSPORT_H

#include "../ext_git2.h"

using namespace HPHP;

int64_t HHVM_FUNCTION(git_cred_has_username,
	const Resource& cred);

Resource HHVM_FUNCTION(git_cred_userpass_plaintext_new,
	const String& username,
	const String& password);

Resource HHVM_FUNCTION(git_cred_ssh_key_new,
	const String& username,
	const String& publickey,
	const String& privatekey,
	const String& passphrase);

Resource HHVM_FUNCTION(git_cred_ssh_custom_new,
	const String& username,
	const String& publickey,
	int64_t publickey_len,
	const Variant& sign_fn,
	const Variant& sign_data);

Resource HHVM_FUNCTION(git_cred_default_new);

Resource HHVM_FUNCTION(git_transport_new,
	const Resource& owner,
	const String& url);

int64_t HHVM_FUNCTION(git_transport_register,
	const String& prefix,
	int64_t priority,
	const Variant& cb,
	const Variant& param);

int64_t HHVM_FUNCTION(git_transport_unregister,
	const String& prefix,
	int64_t priority);

Resource HHVM_FUNCTION(git_transport_dummy,
	const Resource& owner,
	const Variant& payload);

Resource HHVM_FUNCTION(git_transport_local,
	const Resource& owner,
	const Variant& payload);

Resource HHVM_FUNCTION(git_transport_smart,
	const Resource& owner,
	const Variant& payload);

Resource HHVM_FUNCTION(git_smart_subtransport_http,
	const Resource& owner);

Resource HHVM_FUNCTION(git_smart_subtransport_git,
	const Resource& owner);

Resource HHVM_FUNCTION(git_smart_subtransport_ssh,
	const Resource& owner);

#endif

