/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/base/array-init.h"

#include "reflog.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_reflog_read,
	const Resource& repo,
	const String& name)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_reflog *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_reflog_read(&out, HHVM_GIT2_V(repo_, repository), name.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, reflog) = out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_reflog_write,
	const Resource& reflog)
{
	int result;
	int64_t return_value;

	auto reflog_ = dyn_cast<Git2Resource>(reflog);

	result = git_reflog_write(HHVM_GIT2_V(reflog_, reflog));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_reflog_append,
	const Resource& reflog,
	const String& id,
	const Array& committer,
	const String& msg)
{
	int result;
	int64_t return_value;

	git_oid id_;

	auto reflog_ = dyn_cast<Git2Resource>(reflog);
	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	result = git_reflog_append(HHVM_GIT2_V(reflog_, reflog), &id_, NULL, msg.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_reflog_append_to,
	const Resource& repo,
	const String& name,
	const String& id,
	const Array& committer,
	const String& msg)
{
	int result;
	int64_t return_value;

	git_oid id_;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstr(&id_, id.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	result = git_reflog_append_to(HHVM_GIT2_V(repo_, repository), name.c_str(), &id_, NULL, msg.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_reflog_rename,
	const Resource& repo,
	const String& old_name,
	const String& name)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_reflog_rename(HHVM_GIT2_V(repo_, repository), old_name.c_str(), name.c_str());
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_reflog_delete,
	const Resource& repo,
	const String& name)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_reflog_delete(HHVM_GIT2_V(repo_, repository), name.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_reflog_entrycount,
	const Resource& reflog)
{
	size_t result;
	int64_t return_value;

	auto reflog_ = dyn_cast<Git2Resource>(reflog);

	result = git_reflog_entrycount(HHVM_GIT2_V(reflog_, reflog));
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_reflog_entry_byindex,
	const Resource& reflog,
	int64_t idx)
{
	const git_reflog_entry *result;
	auto return_value = req::make<Git2Resource>();

	auto reflog_ = dyn_cast<Git2Resource>(reflog);

	result = git_reflog_entry_byindex(HHVM_GIT2_V(reflog_, reflog), (size_t) idx);
	//HHVM_GIT2_V(return_value, reflog_entry) = result; todo return as array
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_reflog_drop,
	const Resource& reflog,
	int64_t idx,
	int64_t rewrite_previous_entry)
{
	int result;
	int64_t return_value;

	auto reflog_ = dyn_cast<Git2Resource>(reflog);

	result = git_reflog_drop(HHVM_GIT2_V(reflog_, reflog), (size_t) idx, (int) rewrite_previous_entry);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_reflog_entry_id_old,
	const Resource& entry)
{
	const git_oid *result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	auto entry_ = dyn_cast<Git2Resource>(entry);

	result = git_reflog_entry_id_old(HHVM_GIT2_V(entry_, reflog_entry));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

String HHVM_FUNCTION(git_reflog_entry_id_new,
	const Resource& entry)
{
	const git_oid *result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	auto entry_ = dyn_cast<Git2Resource>(entry);

	result = git_reflog_entry_id_new(HHVM_GIT2_V(entry_, reflog_entry));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

Array HHVM_FUNCTION(git_reflog_entry_committer,
	const Resource& entry)
{
	const git_signature *result;
	Array return_value;

	auto entry_ = dyn_cast<Git2Resource>(entry);

	result = git_reflog_entry_committer(HHVM_GIT2_V(entry_, reflog_entry));
	return_value = null_array;
	return return_value;
}

String HHVM_FUNCTION(git_reflog_entry_message,
	const Resource& entry)
{
	const char *result;
	String return_value;

	auto entry_ = dyn_cast<Git2Resource>(entry);

	result = git_reflog_entry_message(HHVM_GIT2_V(entry_, reflog_entry));

	if (result != NULL) {
		return_value = String(result);
	} else {
		return_value = "";
	}

	return return_value;
}

void HHVM_FUNCTION(git_reflog_free,
	const Resource& reflog)
{

	auto reflog_ = dyn_cast<Git2Resource>(reflog);

	git_reflog_free(HHVM_GIT2_V(reflog_, reflog));
}

