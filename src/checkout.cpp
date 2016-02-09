/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/base/array-init.h"
#include "checkout.h"

using namespace HPHP;

int hhvm_git2_array_to_git_checkout_opts(git_checkout_opts **out, Array opts)
{
    git_checkout_opts *__opts = NULL, def = GIT_CHECKOUT_OPTS_INIT;
    char** strings;

    __opts = (git_checkout_opts*) malloc(sizeof(git_checkout_opts*));
    memcpy(__opts, &def, sizeof(git_checkout_opts));
    
    Array __paths = opts[String("oaths")].toArray();
    Array __strings = __paths[String("strings")].toArray();
    size_t count = (size_t) __paths[String("count")].toInt64();
    
    strings = (char**) malloc(count * sizeof(char*));
    for (int i = 0; i < count; i++) {
        strings[i] = __strings[i].toString().mutableData();
    }
    
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
    
    *out = __opts;
    return 0;
}

Array HHVM_FUNCTION(git_checkout_opts_new)
{
    Array return_value;
    
    git_checkout_opts opts = GIT_CHECKOUT_OPTS_INIT;
    
    return_value = make_map_array(
                                  "version" , (int64_t) opts.version,
                                  "checkout_strategy", (int64_t) opts.checkout_strategy,
                                  "disable_filters", (int64_t) opts.disable_filters,
                                  "checkout_strategy", (int64_t) opts.checkout_strategy,
                                  "dir_mode", (int64_t) opts.dir_mode,
                                  "file_mode", (int64_t) opts.file_mode,
                                  "file_open_flags", (int64_t) opts.file_open_flags,
                                  "notify_flags", (int64_t) opts.notify_flags,
                                  "notify_cb", NULL,
                                  "notify_payload", NULL,
                                  "progress_cb", NULL,
                                  "progress_payload", NULL,
                                  "paths", make_map_array("strings", Array::Create(), "count", 0),
                                  "baseline", NULL,
                                  "target_directory", (opts.target_directory ? String(opts.target_directory) : ""),
                                  "our_label", (opts.our_label ? String(opts.our_label) : ""),
                                  "their_label", (opts.their_label ? String(opts.their_label) : ""));
    
    return return_value;
}

int64_t HHVM_FUNCTION(git_checkout_head,
	const Resource& repo,
	const Array& opts)
{
	int result;
    int64_t return_value;
    git_checkout_opts *__opts;
    
    hhvm_git2_array_to_git_checkout_opts(&__opts , opts);
    
    auto repo_ = dyn_cast<Git2Resource>(repo);
    
    result = git_checkout_head(HHVM_GIT2_V(repo_, repository), __opts);

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
	const Array& opts)
{
	int result;
    int64_t return_value;
    git_checkout_opts *__opts;
    
    hhvm_git2_array_to_git_checkout_opts(&__opts , opts);
    
	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_checkout_index(HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(index_, index), __opts);

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
    
    hhvm_git2_array_to_git_checkout_opts(&__opts , opts);
    
	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto treeish_ = dyn_cast<Git2Resource>(treeish);

	result = git_checkout_tree(HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(treeish_, object), __opts);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

