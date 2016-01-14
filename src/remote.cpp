/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/base/builtin-functions.h"

#include "remote.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_remote_create,
	const Resource& repo,
	const String& name,
	const String& url)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_remote *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_remote_create(&out, HHVM_GIT2_V(repo_, repository), name.c_str(), url.c_str());

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	HHVM_GIT2_V(return_value, remote) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_remote_create_with_fetchspec,
	const Resource& repo,
	const String& name,
	const String& url,
	const String& fetch)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_remote *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_remote_create_with_fetchspec(&out, HHVM_GIT2_V(repo_, repository), name.c_str(), url.c_str(), fetch.c_str());

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	HHVM_GIT2_V(return_value, remote) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_remote_create_inmemory,
	const Resource& repo,
	const String& fetch,
	const String& url)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_remote *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_remote_create_inmemory(&out, HHVM_GIT2_V(repo_, repository), fetch.c_str(), url.c_str());

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	HHVM_GIT2_V(return_value, remote) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_remote_load,
	const Resource& repo,
	const String& name)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_remote *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_remote_load(&out, HHVM_GIT2_V(repo_, repository), name.c_str());

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	HHVM_GIT2_V(return_value, remote) = out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_remote_save,
	const Resource& remote)
{
	int result;
	int64_t return_value;

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_save(HHVM_GIT2_V(remote_, remote));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_remote_owner,
	const Resource& remote)
{
	git_repository *result;
	auto return_value = req::make<Git2Resource>();

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_owner(HHVM_GIT2_V(remote_, remote));
	HHVM_GIT2_V(return_value, repository) = result;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_remote_name,
	const Resource& remote)
{
	const char *result;
	String return_value;

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_name(HHVM_GIT2_V(remote_, remote));
	return_value = String(result);
	return return_value;
}

String HHVM_FUNCTION(git_remote_url,
	const Resource& remote)
{
	const char *result;
	String return_value;

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_url(HHVM_GIT2_V(remote_, remote));
	return_value = String(result);
	return return_value;
}

String HHVM_FUNCTION(git_remote_pushurl,
	const Resource& remote)
{
	const char *result;
	String return_value;

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_pushurl(HHVM_GIT2_V(remote_, remote));
	return_value = String(result);
	return return_value;
}

int64_t HHVM_FUNCTION(git_remote_set_url,
	const Resource& remote,
	const String& url)
{
	int result;
	int64_t return_value;

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_set_url(HHVM_GIT2_V(remote_, remote), url.c_str());

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_remote_set_pushurl,
	const Resource& remote,
	const String& url)
{
	int result;
	int64_t return_value;

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_set_pushurl(HHVM_GIT2_V(remote_, remote), url.c_str());

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_remote_add_fetch,
	const Resource& remote,
	const String& refspec)
{
	int result;
	int64_t return_value;

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_add_fetch(HHVM_GIT2_V(remote_, remote), refspec.c_str());

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_remote_get_fetch_refspecs,
	const Resource& array,
	const Resource& remote)
{
	int result;
	int64_t return_value;

	auto array_ = dyn_cast<Git2Resource>(array);
	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_get_fetch_refspecs(HHVM_GIT2_V(array_, strarray), HHVM_GIT2_V(remote_, remote));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_remote_set_fetch_refspecs,
	const Resource& remote,
	const Resource& array)
{
	int result;
	int64_t return_value;

	auto remote_ = dyn_cast<Git2Resource>(remote);
	auto array_ = dyn_cast<Git2Resource>(array);

	result = git_remote_set_fetch_refspecs(HHVM_GIT2_V(remote_, remote), HHVM_GIT2_V(array_, strarray));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_remote_add_push,
	const Resource& remote,
	const String& refspec)
{
	int result;
	int64_t return_value;

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_add_push(HHVM_GIT2_V(remote_, remote), refspec.c_str());

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_remote_get_push_refspecs,
	const Resource& array,
	const Resource& remote)
{
	int result;
	int64_t return_value;

	auto array_ = dyn_cast<Git2Resource>(array);
	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_get_push_refspecs(HHVM_GIT2_V(array_, strarray), HHVM_GIT2_V(remote_, remote));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_remote_set_push_refspecs,
	const Resource& remote,
	const Resource& array)
{
	int result;
	int64_t return_value;

	auto remote_ = dyn_cast<Git2Resource>(remote);
	auto array_ = dyn_cast<Git2Resource>(array);

	result = git_remote_set_push_refspecs(HHVM_GIT2_V(remote_, remote), HHVM_GIT2_V(array_, strarray));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_remote_clear_refspecs,
	const Resource& remote)
{

	auto remote_ = dyn_cast<Git2Resource>(remote);

	git_remote_clear_refspecs(HHVM_GIT2_V(remote_, remote));
}

int64_t HHVM_FUNCTION(git_remote_refspec_count,
	const Resource& remote)
{
	size_t result;
	int64_t return_value;

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_refspec_count(HHVM_GIT2_V(remote_, remote));
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_remote_get_refspec,
	const Resource& remote,
	int64_t n)
{
	const git_refspec *result;
	auto return_value = req::make<Git2Resource>();

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_get_refspec(HHVM_GIT2_V(remote_, remote), (size_t) n);
	//HHVM_GIT2_V(return_value, refspec) = result; todo return as array
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_remote_connect,
	const Resource& remote,
	int64_t direction)
{
	int result;
	int64_t return_value;

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_connect(HHVM_GIT2_V(remote_, remote), (git_direction) direction);

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_remote_ls,
	int64_t size,
	const Resource& remote)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	const git_remote_head **out = NULL;

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_ls(&out, (size_t*) size, HHVM_GIT2_V(remote_, remote));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	//HHVM_GIT2_V(return_value, remote_head) = out; todo return as array
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_remote_download,
	const Resource& remote)
{
	int result;
	int64_t return_value;

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_download(HHVM_GIT2_V(remote_, remote));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_remote_connected,
	const Resource& remote)
{
	int result;
	int64_t return_value;

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_connected(HHVM_GIT2_V(remote_, remote));

    if (result != GIT_OK && result != 1) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_remote_stop,
	const Resource& remote)
{

	auto remote_ = dyn_cast<Git2Resource>(remote);

	git_remote_stop(HHVM_GIT2_V(remote_, remote));
}

void HHVM_FUNCTION(git_remote_disconnect,
	const Resource& remote)
{

	auto remote_ = dyn_cast<Git2Resource>(remote);

	git_remote_disconnect(HHVM_GIT2_V(remote_, remote));
}

void HHVM_FUNCTION(git_remote_free,
	const Resource& remote)
{

	auto remote_ = dyn_cast<Git2Resource>(remote);

	git_remote_free(HHVM_GIT2_V(remote_, remote));
    
    // todo free resource, too
}

int64_t HHVM_FUNCTION(git_remote_update_tips,
	const Resource& remote)
{
	int result;
	int64_t return_value;

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_update_tips(HHVM_GIT2_V(remote_, remote));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_remote_fetch,
	const Resource& remote)
{
	int result;
	int64_t return_value;

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_fetch(HHVM_GIT2_V(remote_, remote));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_remote_valid_url,
	const String& url)
{
	int result;
	int64_t return_value;

	result = git_remote_valid_url(url.c_str());

    if (result != GIT_OK && result != 1) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_remote_supported_url,
	const String& url)
{
	int result;
	int64_t return_value;

	result = git_remote_supported_url(url.c_str());

    if (result != GIT_OK && result != 1) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_remote_list,
	const Resource& repo)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_strarray out;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_remote_list(&out, HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	HHVM_GIT2_V(return_value, strarray) = &out;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_remote_check_cert,
	const Resource& remote,
	int64_t check)
{

	auto remote_ = dyn_cast<Git2Resource>(remote);

	git_remote_check_cert(HHVM_GIT2_V(remote_, remote), (int) check);
}

int64_t HHVM_FUNCTION(git_remote_set_transport,
	const Resource& remote,
	const Resource& transport)
{
	int result;
	int64_t return_value;

	auto remote_ = dyn_cast<Git2Resource>(remote);
	auto transport_ = dyn_cast<Git2Resource>(transport);

	result = git_remote_set_transport(HHVM_GIT2_V(remote_, remote), HHVM_GIT2_V(transport_, transport));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_remote_set_callbacks,
	const Resource& remote,
	const Array& callbacks)
{
	int result;
	int64_t return_value;
    git_remote_callbacks callbacks_ = GIT_REMOTE_CALLBACKS_INIT;

	auto remote_ = dyn_cast<Git2Resource>(remote);
    
    if (is_callable(callbacks[String("credentials")])) {
        // callbacks_.credentials = <todo Konvertierung> callbacks[String("credentials")];
    } else {
        throw SystemLib::AllocExceptionObject("is no callback");
    }
        
	result = git_remote_set_callbacks(HHVM_GIT2_V(remote_, remote), &callbacks_);

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_remote_stats,
	const Resource& remote)
{
	const git_transfer_progress *result;
	auto return_value = req::make<Git2Resource>();

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_stats(HHVM_GIT2_V(remote_, remote));
	//HHVM_GIT2_V(return_value, transfer_progress) = result; todo return as array
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_remote_autotag,
	const Resource& remote)
{
	git_remote_autotag_option_t result;
	int64_t return_value;

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_autotag(HHVM_GIT2_V(remote_, remote));
	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_remote_set_autotag,
	const Resource& remote,
	int64_t value)
{

	auto remote_ = dyn_cast<Git2Resource>(remote);

	git_remote_set_autotag(HHVM_GIT2_V(remote_, remote), (git_remote_autotag_option_t) value);
}

int64_t HHVM_FUNCTION(git_remote_rename,
	const Resource& remote,
	const String& new_name,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_remote_rename_problem_cb callback_ = NULL;
	void *payload_ = NULL;

	auto remote_ = dyn_cast<Git2Resource>(remote);
	callback_ = NULL;

	result = git_remote_rename(HHVM_GIT2_V(remote_, remote), new_name.c_str(), /* todo */ callback_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_remote_update_fetchhead,
	const Resource& remote)
{
	int result;
	int64_t return_value;

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_remote_update_fetchhead(HHVM_GIT2_V(remote_, remote));

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_remote_set_update_fetchhead,
	const Resource& remote,
	int64_t value)
{

	auto remote_ = dyn_cast<Git2Resource>(remote);

	git_remote_set_update_fetchhead(HHVM_GIT2_V(remote_, remote), (int) value);
}

int64_t HHVM_FUNCTION(git_remote_is_valid_name,
	const String& remote_name)
{
	int result;
	int64_t return_value;

	result = git_remote_is_valid_name(remote_name.c_str());

    if (result != GIT_OK && result != 1) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

