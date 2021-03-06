/* Copyright 2013-2016 Matt Tytel
 *
 * mopo is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * mopo is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with mopo.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "twytch_formant_manager.h"

#include "twytch_filter.h"
#include "twytch_operators.h"

namespace mopotwytchsynth {

  FormantManager::FormantManager(int num_formants) : ProcessorRouter(0, 0) {
    Bypass* audio_input = new Bypass();
    Bypass* reset_input = new Bypass();

    registerInput(audio_input->input(), kAudio);
    registerInput(reset_input->input(), kReset);

    addProcessor(audio_input);
    addProcessor(reset_input);

    VariableAdd* total = new VariableAdd(num_formants);
    for (int i = 0; i < num_formants; ++i) {
      Filter* formant = new Filter();
      formant->plug(audio_input, Filter::kAudio);
      formant->plug(reset_input, Filter::kReset);
      formants_.push_back(formant);

      addProcessor(formant);
      total->plugNext(formant);
    }

    addProcessor(total);
    registerOutput(total->output());
  }

  std::complex<mopo_float> FormantManager::getResponse(mopo_float frequency) {
    std::complex<mopo_float> total;
    for (int i = 0; i < formants_.size(); ++i)
      total += formants_[i]->getResponse(frequency);

    return total;
  }
} // namespace mopo
