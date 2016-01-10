/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/system/systemlib.h"

#include "reflog.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_reflog_read,
	const Resource& repo,
	const String& name)
{
	auto return_value = req::make<Git2Resource>();

	git_reflog **out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	git_reflog_read(out, HHVM_GIT2_V(repo_, repository), name.c_str());
	HHVM_GIT2_V(return_value, reflog) = *out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_reflog_write,
	const Resource& reflog)
{
	int result;
	int64_t return_value;

	auto reflog_ = dyn_cast<Git2Resource>(reflog);

	result = git_reflog_write(HHVM_GIT2_V(reflog_, reflog));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_reflog_append,
	const Resource& reflog,
	const String& id,
	const Resource& committer,
	const String& msg)
{
	int result;
	int64_t return_value;

	git_oid *id_ = NULL;

	auto reflog_ = dyn_cast<Git2Resource>(reflog);
	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}
	auto committer_ = dyn_cast<Git2Resource>(committer);

	result = git_reflog_append(HHVM_GIT2_V(reflog_, reflog), id_, HHVM_GIT2_V(committer_, signature), msg.c_str());
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_reflog_append_to,
	const Resource& repo,
	const String& name,
	const String& id,
	const Resource& committer,
	const String& msg)
{
	int result;
	int64_t return_value;

	git_oid *id_ = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}
	auto committer_ = dyn_cast<Git2Resource>(committer);

	result = git_reflog_append_to(HHVM_GIT2_V(repo_, repository), name.c_str(), id_, HHVM_GIT2_V(committer_, signature), msg.c_str());
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
	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_reflog_entry_id_old,
	const Resource& entry)
{
	const git_oid *result;
	char *return_value;

	auto entry_ = dyn_cast<Git2Resource>(entry);

	result = git_reflog_entry_id_old(HHVM_GIT2_V(entry_, reflog_entry));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

String HHVM_FUNCTION(git_reflog_entry_id_new,
	const Resource& entry)
{
	const git_oid *result;
	char *return_value;

	auto entry_ = dyn_cast<Git2Resource>(entry);

	result = git_reflog_entry_id_new(HHVM_GIT2_V(entry_, reflog_entry));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

Resource HHVM_FUNCTION(git_reflog_entry_committer,
	const Resource& entry)
{
	const git_signature *result;
	auto return_value = req::make<Git2Resource>();

	auto entry_ = dyn_cast<Git2Resource>(entry);

	result = git_reflog_entry_committer(HHVM_GIT2_V(entry_, reflog_entry));
	//HHVM_GIT2_V(return_value, signature) = result; todo return as array
	return Resource(return_value);
}

String HHVM_FUNCTION(git_reflog_entry_message,
	const Resource& entry)
{
	const char *result;
	String return_value;

	auto entry_ = dyn_cast<Git2Resource>(entry);

	result = git_reflog_entry_message(HHVM_GIT2_V(entry_, reflog_entry));
	return_value = String(result);
	return return_value;
}

void HHVM_FUNCTION(git_reflog_free,
	const Resource& reflog)
{

	auto reflog_ = dyn_cast<Git2Resource>(reflog);

	git_reflog_free(HHVM_GIT2_V(reflog_, reflog));
}

