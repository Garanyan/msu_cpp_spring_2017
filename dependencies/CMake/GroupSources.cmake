# Based on http://stackoverflow.com/a/31987079/399601
# This macro hierarchically (repeating the directory structure)
# organizes the files in the IDE project

# GroupSourcesWithBase takes basedir from arg
macro(GroupSourcesWithBase target base)
get_filename_component(basedir ${base} ABSOLUTE)
get_target_property(srcs ${target} SOURCES)

foreach(FILE ${srcs})
    # Get the directory of the source file	
	get_filename_component(absfile ${FILE} ABSOLUTE)
    get_filename_component(PARENT_DIR "${absfile}" DIRECTORY)	

    # Remove common directory prefix to make the group
    string(REPLACE "${basedir}" "" GROUP "${PARENT_DIR}")

    # Make sure we are using windows slashes
    string(REPLACE "/" "\\" GROUP "${GROUP}")

    source_group("${GROUP}" FILES "${FILE}")	
endforeach()
endmacro()

# GroupSourcesWithBase takes sources and basedir from target
macro(GroupSources target)
get_target_property(srcs ${target} SOURCES)
get_target_property(basedir ${target} SOURCE_DIR)

foreach(FILE ${srcs})
    # Get the directory of the source file
    get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)

    # Remove common directory prefix to make the group
    string(REPLACE "${basedir}" "" GROUP "${PARENT_DIR}")

    # Make sure we are using windows slashes
    string(REPLACE "/" "\\" GROUP "${GROUP}")

    source_group("${GROUP}" FILES "${FILE}")
endforeach()
endmacro()

# GroupSourcesSubStr also remove substr in the middle of group name
macro(GroupSourcesWithBaseAndSubStr target base substr)
get_filename_component(basedir ${base} ABSOLUTE)
get_target_property(srcs ${target} SOURCES)

foreach(FILE ${srcs})
    # Get the directory of the source file	
	get_filename_component(absfile ${FILE} ABSOLUTE)
    get_filename_component(PARENT_DIR "${absfile}" DIRECTORY)

    # Remove common directory prefix to make the group
    string(REPLACE "${basedir}" "" GROUP "${PARENT_DIR}")
	
	# Remove common directory prefix to make the group
    string(REPLACE "${substr}" "" GROUP "${GROUP}")

    # Make sure we are using windows slashes
    string(REPLACE "/" "\\" GROUP "${GROUP}")

    source_group("${GROUP}" FILES "${FILE}")	
endforeach()
endmacro()