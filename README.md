# Open-Vulkan-Game-Framework

OVGF is meant, for now, to be a Vulkan based rapid prototyping tool to assist in game development.

Once the framework is sufficient as such a tool, then development will shift focus to being suitable for release products.

The goal is to eventually build this Framework out into a proper engine. Hopefully we can get rid of some of the drudgery without sacrificing the power.

# Stability

The framework is in alpha and currently has no stable release. While it's being built there is no gaurentee it will work. While it should always compile, it may not function as expected until a full release.

# File naming structure

Files are named with the following convention:

ovfg<Namespace1><2>...<n>[Class/Struct name](Libraires based on)
  
  e.g. ovgfStructsQueriesVersion - structure queries for the Version structure 
          or 
             ovgfObjectsWindowGLFW - window object based on GLFW
