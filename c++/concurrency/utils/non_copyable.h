/* Copyright (C)
 *
 * Copyright 2013 Matthew Everett Hoggan
 *
 * Licensed under the Apache License, Version 2.0 (the "License")
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writting, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef SYSTEM_NON_COPYABLE_HPP_INCLUDED
#define SYSTEM_NON_COPYABLE_HPP_INCLUDED

#include <system/declspec.h>

namespace  gl_wrapper
{
  namespace system
  {
    class SYSTEM_API non_copyable
    {
    protected:
      non_copyable() {}
      ~non_copyable() {}
    private:
      non_copyable(const non_copyable &);
      non_copyable &operator=(const non_copyable &);
    };
  }
}
#endif
