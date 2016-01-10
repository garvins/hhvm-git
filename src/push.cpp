/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/system/systemlib.h"

#include "push.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_push_new,
	const Resource& remote)
{
	auto return_value = req::make<Git2Resource>();

	git_push **out = NULL;

	auto remote_ = dyn_cast<Git2Resource>(remote);

	git_push_new(out, HHVM_GIT2_V(remote_, remote));
	HHVM_GIT2_V(return_value, push) = *out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_push_set_options,
	const Resource& push,
	const Resource& opts)
{
	int result;
	int64_t return_value;

	auto push_ = dyn_cast<Git2Resource>(push);
	auto opts_ = dyn_cast<Git2Resource>(opts);

	result = git_push_set_options(HHVM_GIT2_V(push_, push), HHVM_GIT2_V(opts_, push_options));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_push_set_callbacks,
	const Resource& push,
	const Variant& pack_progress_cb,
	const Variant& pack_progress_cb_payload,
	const Variant& transfer_progress_cb,
	const Variant& transfer_progress_cb_payload)
{
	int result;
	int64_t return_value;

	git_packbuilder_progress pack_progress_cb_ = NULL;
	void *pack_progress_cb_payload_ = NULL;
	git_push_transfer_progress transfer_progress_cb_ = NULL;
	void *transfer_progress_cb_payload_ = NULL;

	auto push_ = dyn_cast<Git2Resource>(push);
	pack_progress_cb_ = NULL;
	transfer_progress_cb_ = NULL;

	result = git_push_set_callbacks(HHVM_GIT2_V(push_, push), /* todo */ pack_progress_cb_, pack_progress_cb_payload_, /* todo */ transfer_progress_cb_, transfer_progress_cb_payload_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_push_add_refspec,
	const Resource& push,
	const String& refspec)
{
	int result;
	int64_t return_value;

	auto push_ = dyn_cast<Git2Resource>(push);

	result = git_push_add_refspec(HHVM_GIT2_V(push_, push), refspec.c_str());
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_push_update_tips,
	const Resource& push)
{
	int result;
	int64_t return_value;

	auto push_ = dyn_cast<Git2Resource>(push);

	result = git_push_update_tips(HHVM_GIT2_V(push_, push));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_push_finish,
	const Resource& push)
{
	int result;
	int64_t return_value;

	auto push_ = dyn_cast<Git2Resource>(push);

	result = git_push_finish(HHVM_GIT2_V(push_, push));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_push_unpack_ok,
	const Resource& push)
{
	int result;
	int64_t return_value;

	auto push_ = dyn_cast<Git2Resource>(push);

	result = git_push_unpack_ok(HHVM_GIT2_V(push_, push));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_push_status_foreach,
	const Resource& push,
	int64_t cb,
	const Variant& data)
{
	int result;
	int64_t return_value;

	void *data_ = NULL;

	auto push_ = dyn_cast<Git2Resource>(push);

	//result = git_push_status_foreach(HHVM_GIT2_V(push_, push), (int) cb, data_); todo
	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_push_free,
	const Resource& push)
{

	auto push_ = dyn_cast<Git2Resource>(push);

	git_push_free(HHVM_GIT2_V(push_, push));
}

