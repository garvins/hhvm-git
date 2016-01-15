/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/base/array-init.h"
#include "checkout.h"

using namespace HPHP;

Array HHVM_FUNCTION(git_checkout_opts_new)
{
    Array return_value;
    
    return_value = make_map_array(
                                  "version" , GIT_CHECKOUT_OPTS_VERSION,
                                  "checkout_strategy", 0,
                                  "disable_filters", 0,
                                  "checkout_strategy", 0,
                                  "dir_mode", 0,
                                  "file_mode", 0,
                                  "file_open_flags", 0,
                                  "notify_flags", 0,
                                  "notify_cb", NULL,
                                  "notify_payload", NULL,
                                  "progress_cb", NULL,
                                  "progress_payload", NULL,
                                  "paths", make_map_array("strings", Array::Create(), "count", 0),
                                  "baseline", NULL,
                                  "target_directory", "",
                                  "our_label", "",
                                  "their_label", "");
    
    return return_value;
}

int64_t HHVM_FUNCTION(git_checkout_head,
	const Resource& repo,
	const Resource& opts)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto opts_ = dyn_cast<Git2Resource>(opts);

	result = git_checkout_head(HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(opts_, checkout_opts));

    if (result == GIT_EUNBORNBRANCH) {
        /* HEAD points to an non existing branch */
        const git_error *error = giterr_last();
        SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
    }
    if (result != GIT_OK) {
        const git_error *error = giterr_last();
        SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_checkout_index,
	const Resource& repo,
	const Resource& index,
	const Resource& opts)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto index_ = dyn_cast<Git2Resource>(index);
	auto opts_ = dyn_cast<Git2Resource>(opts);

	result = git_checkout_index(HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(index_, index), HHVM_GIT2_V(opts_, checkout_opts));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_checkout_tree,
	const Resource& repo,
	const Resource& treeish,
	const Array& opts)
{
	int result;
	int64_t return_value;
    git_checkout_opts *__opts;
    
    Array __paths = opts[String("oaths")].toArray();
    size_t count = (size_t) __paths[String("count")].toInt64();
    Array __strings = __paths[String("strings")].toArray();
    char** strings;
    
    strings = (char**) malloc(count * sizeof(char*));
    for (int i = 0; i < count; i++) {
    	strings[i] = __strings[i].toString().mutableData();
    }
    
    __opts = (git_checkout_opts*) malloc(sizeof(git_checkout_opts*));
    
    __opts->version = (unsigned int) opts[String("version")].toInt64();
    __opts->checkout_strategy = (unsigned int) opts[String("checkout_strategy")].toInt64();
    __opts->disable_filters = (int) opts[String("disable_filters")].toInt64();
    __opts->dir_mode = (unsigned int) opts[String("dir_mode")].toInt64();
    __opts->file_mode = (unsigned int) opts[String("file_mode")].toInt64();
    __opts->file_open_flags = (int) opts[String("file_open_flags")].toInt64();
    __opts->notify_flags = (unsigned int) opts[String("notify_flags")].toInt64();
    __opts->notify_cb = NULL; //todo
    __opts->notify_payload = NULL; //todo
    __opts->progress_cb = NULL; //todo
	__opts->progress_payload = NULL; //todo
    __opts->paths.strings = strings;
    __opts->paths.count = count;
    __opts->target_directory = opts[String("target_directory")].toString().c_str();
    __opts->our_label = opts[String("our_label")].toString().c_str();
    __opts->their_label = opts[String("their_label")].toString().c_str();

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto treeish_ = dyn_cast<Git2Resource>(treeish);

	result = git_checkout_tree(HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(treeish_, object), __opts);
	return_value = (int64_t) result;
	return return_value;
}

