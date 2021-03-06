#ifndef WORKSPACELOADER_H
#define WORKSPACELOADER_H

class Context;
class RackElement;
#include <KLib/fs/File.h>
#include <unordered_map>
#include "StatusCallback.h"

#include "../lib/tinyxml2/tinyxml2.h"
using namespace tinyxml2;

/** exception handling */
class WorkspaceLoaderException : public std::exception {
public:
	WorkspaceLoaderException(const std::string& msg) : msg(msg) {;}
	const char* what() const throw() {return msg.c_str();}
private:
	std::string msg;
};


/**
 * load workspace from file
 */
class WorkspaceLoader {

public:

	/** ctor */
	WorkspaceLoader(Context& ctx);

	/** dtor */
	~WorkspaceLoader();

	/** load the given file */
	void load(const K::File& file, StatusCallback sc = nullptr);



private:

	/** parse loaded XML string */
	void parseXML(const std::string& xml, StatusCallback sc);


	/** load all workspace settings */
	void loadSettings(XMLElement* nSettings, StatusCallback sc);

	/** load all rack elements */
	void loadRackElements(XMLElement* nRack, StatusCallback sc);

	/** load all bindings */
	void loadBindings(XMLElement* nBindings, StatusCallback sc);

	/** load all tracks */
	void loadTracks(XMLElement* nTracks, StatusCallback sc);


	/** the context to store to */
	Context& ctx;

	/** convert id to lement */
	std::unordered_map<unsigned int, RackElement*> idToElement;


};

#endif // WORKSPACELOADER_H
