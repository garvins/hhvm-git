/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/system/systemlib.h"

#include "transport.h"

using namespace HPHP;

int64_t HHVM_FUNCTION(git_cred_has_username,
	const Resource& cred)
{
	int result;
	int64_t return_value;

	auto cred_ = dyn_cast<Git2Resource>(cred);

	result = git_cred_has_username(HHVM_GIT2_V(cred_, cred));
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_cred_userpass_plaintext_new,
	const String& username,
	const String& password)
{
	auto return_value = req::make<Git2Resource>();

	git_cred **out = NULL;

	git_cred_userpass_plaintext_new(out, username.c_str(), password.c_str());
	HHVM_GIT2_V(return_value, cred) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_cred_ssh_key_new,
	const String& username,
	const String& publickey,
	const String& privatekey,
	const String& passphrase)
{
	auto return_value = req::make<Git2Resource>();

	git_cred **out = NULL;

	git_cred_ssh_key_new(out, username.c_str(), publickey.c_str(), privatekey.c_str(), passphrase.c_str());
	HHVM_GIT2_V(return_value, cred) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_cred_ssh_custom_new,
	const String& username,
	const String& publickey,
	int64_t publickey_len,
	const Variant& sign_fn,
	const Variant& sign_data)
{
	auto return_value = req::make<Git2Resource>();

	git_cred **out = NULL;
	git_cred_sign_callback sign_fn_ = NULL;
	void *sign_data_ = NULL;

	sign_fn_ = NULL;

	git_cred_ssh_custom_new(out, username.c_str(), publickey.c_str(), (size_t) publickey_len, /* todo */ sign_fn_, sign_data_);
	HHVM_GIT2_V(return_value, cred) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_cred_default_new)
{
	auto return_value = req::make<Git2Resource>();

	git_cred **out = NULL;

	git_cred_default_new(out);
	HHVM_GIT2_V(return_value, cred) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_transport_new,
	const Resource& owner,
	const String& url)
{
	auto return_value = req::make<Git2Resource>();

	git_transport **out = NULL;

	auto owner_ = dyn_cast<Git2Resource>(owner);

	git_transport_new(out, HHVM_GIT2_V(owner_, remote), url.c_str());
	HHVM_GIT2_V(return_value, transport) = *out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_transport_register,
	const String& prefix,
	int64_t priority,
	const Variant& cb,
	const Variant& param)
{
	int result;
	int64_t return_value;

	git_transport_cb cb_ = NULL;
	void *param_ = NULL;

	cb_ = NULL;

	result = git_transport_register(prefix.c_str(), (unsigned) priority, /* todo */ cb_, param_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_transport_unregister,
	const String& prefix,
	int64_t priority)
{
	int result;
	int64_t return_value;

	result = git_transport_unregister(prefix.c_str(), (unsigned) priority);
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_transport_dummy,
	const Resource& owner,
	const Variant& payload)
{
	auto return_value = req::make<Git2Resource>();

	git_transport **out = NULL;
	void *payload_ = NULL;

	auto owner_ = dyn_cast<Git2Resource>(owner);

	git_transport_dummy(out, HHVM_GIT2_V(owner_, remote), payload_);
	HHVM_GIT2_V(return_value, transport) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_transport_local,
	const Resource& owner,
	const Variant& payload)
{
	auto return_value = req::make<Git2Resource>();

	git_transport **out = NULL;
	void *payload_ = NULL;

	auto owner_ = dyn_cast<Git2Resource>(owner);

	git_transport_local(out, HHVM_GIT2_V(owner_, remote), payload_);
	HHVM_GIT2_V(return_value, transport) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_transport_smart,
	const Resource& owner,
	const Variant& payload)
{
	auto return_value = req::make<Git2Resource>();

	git_transport **out = NULL;
	void *payload_ = NULL;

	auto owner_ = dyn_cast<Git2Resource>(owner);

	git_transport_smart(out, HHVM_GIT2_V(owner_, remote), payload_);
	HHVM_GIT2_V(return_value, transport) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_smart_subtransport_http,
	const Resource& owner)
{
	auto return_value = req::make<Git2Resource>();

	git_smart_subtransport **out = NULL;

	auto owner_ = dyn_cast<Git2Resource>(owner);

	git_smart_subtransport_http(out, HHVM_GIT2_V(owner_, transport));
	HHVM_GIT2_V(return_value, smart_subtransport) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_smart_subtransport_git,
	const Resource& owner)
{
	auto return_value = req::make<Git2Resource>();

	git_smart_subtransport **out = NULL;

	auto owner_ = dyn_cast<Git2Resource>(owner);

	git_smart_subtransport_git(out, HHVM_GIT2_V(owner_, transport));
	HHVM_GIT2_V(return_value, smart_subtransport) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_smart_subtransport_ssh,
	const Resource& owner)
{
	auto return_value = req::make<Git2Resource>();

	git_smart_subtransport **out = NULL;

	auto owner_ = dyn_cast<Git2Resource>(owner);

	git_smart_subtransport_ssh(out, HHVM_GIT2_V(owner_, transport));
	HHVM_GIT2_V(return_value, smart_subtransport) = *out;
	return Resource(return_value);
}

