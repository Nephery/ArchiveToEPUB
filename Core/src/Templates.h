#pragma once

#include <string>

// None of these objects are instantiable

class Templates
{
public:
	class XHTML;
	class SVG;

	static void init();
private:
	Templates();
	~Templates();
};

class Templates::XHTML
{
friend class Templates;
public:
	static std::string generate();
protected:
	static void fetch();
private:
	const static std::string _path;
	static std::string _template;
	XHTML();
	~XHTML();
};

class Templates::SVG
{
friend class Templates;
public:
	static std::string generate();
protected:
	static void fetch();
private:
	const static std::string _path;
	static std::string _template;
	SVG();
	~SVG();
};