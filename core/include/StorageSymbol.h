/*
* Copyright 2018 Coati Software KG
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef SOURCETRAIL_STORAGE_SYMBOL_H
#define SOURCETRAIL_STORAGE_SYMBOL_H

#include "DefinitionKind.h"

namespace sourcetrail
{
	struct StorageSymbol
	{
		StorageSymbol()
			: id(0)
			, definitionKind(definitionKindToInt(DEFINITION_EXPLICIT))
		{}

		StorageSymbol(int id, int definitionKind)
			: id(id)
			, definitionKind(definitionKind)
		{}

		int id;
		int definitionKind;
	};
}

#endif // SOURCETRAIL_STORAGE_SYMBOL_H