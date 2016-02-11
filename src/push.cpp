/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/base/builtin-functions.h"
#include "hphp/runtime/base/array-init.h"

#include "push.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_push_new,
	const Resource& remote)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_push *out = NULL;

	auto remote_ = dyn_cast<Git2Resource>(remote);

	result = git_push_new(&out, HHVM_GIT2_V(remote_, remote));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, push) = out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_push_set_options,
	const Resource& push,
	const Array& opts)
{
	int result;
	int64_t return_value;

	auto push_ = dyn_cast<Git2Resource>(push);

	result = git_push_set_options(HHVM_GIT2_V(push_, push), NULL);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

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

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

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

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

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

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

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

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

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

	if (result != GIT_OK && result != 1) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

typedef struct hhvm_git2_push_status_foreach_cb_t {
    Variant callback;
    Variant payload;
} hhvm_git2_push_status_foreach_cb_t;

static int hhvm_git2_push_status_foreach_cb(const char *ref, const char *msg, void *data)
{
    hhvm_git2_push_status_foreach_cb_t *cb = (hhvm_git2_push_status_foreach_cb_t*) data;
    String param_ref = "", param_msg = "";
    Variant result;
    Array arr;
    int retval = 0;
    
    if (cb != NULL) {
        if (ref != NULL) {
            param_ref = String(ref);
        }
        if (msg != NULL) {
            param_msg = String(msg);
        }
        
        if (cb->payload.isInitialized()) {
            arr = make_packed_array(param_ref, param_msg, cb->payload);
        } else {
            arr = make_packed_array(param_ref, param_msg);
        }
        
        result = vm_call_user_func(cb->callback, arr);
    }
    
    if (result.isInteger()) {
        retval = (int) result.toInt64();
    }
    
    return retval;
}

int64_t HHVM_FUNCTION(git_push_status_foreach,
	const Resource& push,
    const Variant& cb,
	const Variant& data)
{
	int result;
	int64_t return_value;
    
    hhvm_git2_push_status_foreach_cb_t *payload = (hhvm_git2_push_status_foreach_cb_t*) calloc(1, sizeof(hhvm_git2_push_status_foreach_cb_t));
    payload->callback = cb;
    payload->payload = data;

	auto push_ = dyn_cast<Git2Resource>(push);

    result = git_push_status_foreach(HHVM_GIT2_V(push_, push), hhvm_git2_push_status_foreach_cb, payload);
    return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_push_free,
	const Resource& push)
{

	auto push_ = dyn_cast<Git2Resource>(push);

	git_push_free(HHVM_GIT2_V(push_, push));
}

